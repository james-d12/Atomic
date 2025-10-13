#!/usr/bin/env bash
set -euo pipefail

COMPILERS=(${COMPILERS:-g++})
STANDARDS=(${STANDARDS:-c++17})
MODES=(${MODES:-Debug})

echo "🏗️  Running build matrix"
echo "Compilers: ${COMPILERS[*]}"
echo "Standards: ${STANDARDS[*]}"
echo "Modes: ${MODES[*]}"
echo

for COMPILER in "${COMPILERS[@]}"; do
  for STANDARD in "${STANDARDS[@]}"; do
    for MODE in "${MODES[@]}"; do
      echo "::group::$COMPILER ($STANDARD, $MODE)"
      BUILD_DIR="build-${COMPILER}-${STANDARD}-${MODE}"
      cmake -E make_directory "$BUILD_DIR"
      cd "$BUILD_DIR"
      cmake "$GITHUB_WORKSPACE" \
        -DCMAKE_BUILD_TYPE="$MODE" \
        -DCMAKE_CXX_FLAGS="-std=$STANDARD" \
        -DCMAKE_CXX_COMPILER="$COMPILER"
      cmake --build . --config "$MODE"
      ./Tests || exit 1
      cd ..
      echo "::endgroup::"
    done
  done
done
