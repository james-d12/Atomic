#!/bin/bash 

if [ ! -d "./Dokky" ]; then 
	echo "Dokky not found, installing now."
	command -v git &> /dev/null && git clone https://github.com/james-d12/Dokky.git 
else
	echo "Getting latest version.."
	cd ./Dokky
	git pull origin 
	cd ../
fi 

echo "Copying configuration file."
cp ./docgen.json "./Dokky/"
cd ./Dokky
echo "Generating documentation."
python3 ./generator.py ./docgen.json 
cd ../

