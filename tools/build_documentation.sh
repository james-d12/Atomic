#!/bin/bash 

if [ ! -d "./Dokky" ]; then 
	command -v git &> /dev/null && git clone https://github.com/james-d12/Dokky.git 
fi 

cp ./docgen.json "./Dokky/"
cd "./Dokky"
python ./generator.py ./docgen.json 
cd "../"

