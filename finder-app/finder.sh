#!/bin/bash


if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <filesdir> <searchstr>"
  exit 1
fi

filesdir="$1"
searchstr="$2"

if [ ! -d "$filesdir" ]; then
  echo "Error: '$filesdir' is not a valid directory."
  exit 1
fi

file_count=$(find "$filesdir" -type f | wc -l)

matching_lines=$(grep -F "$searchstr" $(find "$filesdir" -type f) 2>/dev/null | wc -l)

echo "The number of files are $file_count and the number of matching lines are $matching_lines"
