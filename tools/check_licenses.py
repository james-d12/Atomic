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

def get_license():
    with open("include/atomic.hpp") as file:
        license = file.readlines()[0:7]
    return license

def check_licenses(files):
    hasFailed = False
    license = get_license()
    for file in files:
        with open(file) as f:
            currentLicense = f.readlines()[0:7]
            if(currentLicense != license):
                print("Failed License Check! - ", file.name)
                hasFailed = True
            else:
                print("Passed License Check! - ", file.name)
    return hasFailed

def run_check():
    filterList = [ ".hpp", ".cpp", ".h"]
    include_files = get_files("./include", filterList)
    test_files = get_files("./tests", filterList)
    files = include_files + test_files 
    check_licenses(files)

if __name__ == "__main__":
    hasFailed = run_check()
    exit(0) if hasFailed == False else exit(1)