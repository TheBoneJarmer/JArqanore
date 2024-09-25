#!/bin/bash

echo "Generating header files"
cd src/java
javac -h ../cpp/ `find . -type f -name '*.java'`
rm `find . -type f -name '*.class'`
