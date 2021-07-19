import os
import sys
import re

def to_snake(string):
    pattern = re.compile('((?<=[a-z0-9])[A-Z]|(?!^)[A-Z](?=[a-z]))')
    result = pattern.sub(r'_\1', string).lower()
    return result

def get_files(directoryName, filterList=[]):
    files = []
    with os.scandir(directoryName) as directory:
        for entry in directory:
            if(entry.is_dir()):
                files += (get_files(entry.path, filterList))
            else:
                if len(filterList) >= 1:
                    for f in filterList:
                        if f in str(entry):
                            files.append(entry)   
                            break
                else:
                    files.append(entry)   
    return files
def process_filename(fileName):
    fileName = fileName.replace("_", "")
    return (fileName == to_snake(fileName))

def check_files(files):
    hasFailed = False
    for file in files:
        if(process_filename(file.name) == False):
            print("Failed File Name Check! - ", file.name)
            hasFailed = True
        else:
            print("Passed File Name Check! - ", file.name)
    return hasFailed

def check_file_names(files):
    return check_files(files)

def run_check():
    # Check file names
    filterList = [ ".hpp", ".cpp", ".h"]
    include_files = get_files("./include", filterList)
    test_files = get_files("./tests", filterList)
    files = include_files + test_files

    passedFileNameCheck = check_file_names(files)
    return (passedFileNameCheck)

if __name__ == "__main__":
    hasFailed = run_check()
    exit(0) if hasFailed == False else exit(1)