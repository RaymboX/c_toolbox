#!/bin/bash

#mettre make_ez dans le project folder

PROJECT_NAME="projectname"

MAKE_EXIST="$(find Makefile | grep -c Makefile)"
#echo $MAKE_EXIST
if [ $MAKE_EXIST == 0 ]; then
	$(find ./SRC/*.c > Srcs.txt)
	echo "Existe pas"
else
	echo "existe"
fi


