#!/bin/bash

JAVAC="$JAVA_HOME/bin/javac"
JAR="$JAVA_HOME/bin/jar"
JAVADOC="$JAVA_HOME/bin/javadoc"

rm -rf ./out 2> /dev/null
mkdir out
mkdir out/lib

echo "Generating cmake files"
cd src/cpp/
rm -rf ./build 2> /dev/null
mkdir build
cd build
CMAKE_OUTPUT=$(cmake .. 2>&1)
CMAKE_OUTPUT_EXITCODE=$?

if [[ CMAKE_OUTPUT_EXITCODE -ne 0 ]];
then
	echo "$CMAKE_OUTPUT"
	exit $CMAKE_OUTPUT_EXITCODE
fi

echo "Compiling native libary"
CMAKE_BUILD_OUTPUT=$(cmake --build . 2>&1)
CMAKE_BUILD_OUTPUT_EXITCODE=$?

if [[ CMAKE_BUILD_OUTPUT_EXITCODE -ne 0 ]];
then
	echo "$CMAKE_BUILD_OUTPUT"
	exit $CMAKE_BUILD_OUTPUT_EXITCODE
fi
cp *.so ../../../out
cd ../../..

echo "Compiling java library"
cd src/java
JAVAC_OUTPUT=$($JAVAC -d ../../out -g `find . -type f -name "*.java"` 2>&1)
JAVAC_OUTPUT_EXITCODE=$?

if [[ JAVAC_OUTPUT_EXITCODE -ne 0 ]];
then
	echo "$JAVAC_OUTPUT"
	exit $JAVAC_OUTPUT_EXITCODE
fi


echo "Generating docs"
JAVADOC_OUTPUT=$($JAVADOC -d ../../out/doc/ `find . -type f -name "*.java"` 2>&1)
JAVADOC_OUTPUT_EXITCODE=$?

if [[ JAVADOC_OUTPUT_EXITCODE -ne 0 ]];
then
	echo "$JAVADOC_OUTPUT"
	exit $JAVADOC_OUTPUT_EXITCODE
fi
cd ../..

echo "Generating jar"
cd out
JAR_OUTPUT=$($JAR -cf jarqanore.jar ./be/ 2>&1)
JAR_OUTPUT_EXITCODE=$?

if [[ JAR_OUTPUT_EXITCODE -ne 0 ]];
then
	echo "$JAR_OUTPUT"
	exit $JAR_OUTPUT_EXITCODE
fi
cd ..

echo "Cleaning up"
cd out
rm -rf ./be ./lib

