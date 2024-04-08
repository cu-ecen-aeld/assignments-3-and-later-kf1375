#!/bin/bash

if [ $# -ne 2 ]; then
    echo "ERROR: Invalid Number of Arguments.
    Total number of arguments should be 2.
    1- Directory Path
    2- String to be searched in the specified directory path."
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]; then
    echo "${filesdir} is not a directory!"
    exit 1
fi

num_of_lines=$(find "$filesdir" -type f | wc -l)
matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are ${num_of_lines} and the number of matching lines are ${matching_lines}"
