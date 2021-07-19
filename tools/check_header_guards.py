import os 
import sys 

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

def check_header_guard(file):
    with open(file) as f:
        lines = f.readlines()
        headerGuardCheck = (lines[7])[8:].split()
        headerGuardDefine = (lines[8])[8:].split()
        headerGuardEnd = (lines[len(lines)-1])[8:].split()
        return (headerGuardCheck == headerGuardDefine and headerGuardCheck == headerGuardEnd)

def check_header_guards(files):
    hasFailed = False
    for file in files:
        if(check_header_guard(file) == False):
            print("Failed Header Guard Check! - ", file.name)
            hasFailed = True
        else:
            print("Passed Header Guard Check! - ", file.name)
    return hasFailed

def run_check():
    filterList = [ ".hpp", ".h"]
    include_files = get_files("./include", filterList)
    return check_header_guards(include_files)

if __name__ == "__main__":
    hasFailed = run_check()
    exit(0) if hasFailed == False else exit(1)