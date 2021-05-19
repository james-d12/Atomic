#!/usr/bin/bash 

check_directory_and_dependencies(){
    sourceFolder="$(pwd)/include"

    if [[ "${sourceFolder: -14}" != "Atomic/include" ]]; then
        echo "Please run in Atomic's Root Directory."
        exit 1
    fi 

    if ! command -v git &> /dev/null; then
        echo "Git not installed."
        exit 1
    fi

    if ! command -v python &> /dev/null; then
        echo "Python not installed."
        exit 1
    fi
}

generate_documentation(){
    git clone https://github.com/james-d12/Dokky.git 
    python ./Dokky/generator.py ../docgen.json
}

check_directory_and_dependencies
generate_documentation