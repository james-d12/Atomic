#!/usr/bin/env bash
set -euo pipefail

# Fail early if required environment variables are missing
if [ -z "${COMPILERS:-}" ]; then
  echo "❌ COMPILERS is required"
  exit 1
fi

if [ -z "${STANDARDS:-}" ]; then
  echo "❌ STANDARDS is required"
  exit 1
fi

if [ -z "${MODES:-}" ]; then
  echo "❌ MODES is required"
  exit 1
fi

# Convert space-separated strings into arrays
COMPILERS=($COMPILERS)
STANDARDS=($STANDARDS)
MODES=($MODES)

echo "🏗️  Running build matrix"
echo "Compilers: ${COMPILERS[*]}"
echo "Standards: ${STANDARDS[*]}"
echo "Modes: ${MODES[*]}"
echo

# Track failed combinations
failures=()

for COMPILER in "${COMPILERS[@]}"; do
  for STANDARD in "${STANDARDS[@]}"; do
    for MODE in "${MODES[@]}"; do
      echo "::group::$COMPILER ($STANDARD, $MODE)"
      BUILD_DIR="build-${COMPILER}-${STANDARD}-${MODE}"

      cmake -E make_directory "$BUILD_DIR"
      cd "$BUILD_DIR"

      if ! cmake "$GITHUB_WORKSPACE" \
          -DCMAKE_BUILD_TYPE="$MODE" \
          -DCMAKE_CXX_FLAGS="-std=$STANDARD" \
          -DCMAKE_CXX_COMPILER="$COMPILER"; then
        failures+=("$COMPILER $STANDARD $MODE (cmake configure)")
        cd ..
        echo "::endgroup::"
        continue
      fi

      if ! cmake --build . --config "$MODE"; then
        failures+=("$COMPILER $STANDARD $MODE (build)")
        cd ..
        echo "::endgroup::"
        continue
      fi

      if ! ./Tests; then
        failures+=("$COMPILER $STANDARD $MODE (tests)")
        cd ..
        echo "::endgroup::"
        continue
      fi

      cd ..
      echo "::endgroup::"
    done
  done
done

# Summary
echo
echo "🧾 Summary:"
if [ ${#failures[@]} -eq 0 ]; then
  echo "✅ All builds and tests passed!"
else
  echo "❌ ${#failures[@]} failed combination(s):"
  for fail in "${failures[@]}"; do
    echo "  - $fail"
  done
  exit 1
fi
