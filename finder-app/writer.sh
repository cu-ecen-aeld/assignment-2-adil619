#!/bin/bash

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <writefile> <writestr>"
  exit 1
fi

writefile="$1"
writestr="$2"

# Create the directory path if it doesn't exist
mkdir -p "$(dirname "$writefile")"

# Try to create (or overwrite) the file with the given string
# If writing fails, print an error and exit with code 1
if ! echo "$writestr" > "$writefile"; then
  echo "Error: Could not create or write to file '$writefile'"
  exit 1
fi