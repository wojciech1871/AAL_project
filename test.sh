#!/bin/bash
POINTS_PATH=pointsFiles
EXECUTABLE_PATH=cmake-build-debug/src

for file in ${POINTS_PATH}/*

do
	echo File ${file} results:
	./${EXECUTABLE_PATH}/prog -m1 << ${file}
done
