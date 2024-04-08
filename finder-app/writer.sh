#!/bin/bash

if [ $# -ne 2 ]; then
    echo "ERROR: Invalid Number of Arguments.
    Total number of arguments should be 2.
    1- Directory Path
    2- String to be searched in the specified directory path."
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p $(dirname $writefile) && touch ${writefile} && echo ${writestr} > ${writefile}

if [ $? -eq 1 ]; then
    echo "File could not be created"
    exit 1
fi