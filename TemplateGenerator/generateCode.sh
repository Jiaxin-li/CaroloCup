#!/bin/bash


if (( $# != 3 ))
then
  echo "Usage:./generateCode.sh <namespace> <component> <absolutePath>"
  exit 1
fi
DIR=component
if [ ! -d "$DIR" ]; then
 	echo "Run the script in the correct directory"
	exit 1  # Control will enter here if $DIRECTORY doesn't exist.
fi

NAMESPACE=$1
COMPONENT_NAME=$2
PATH_ARG=$3



cp -R $DIR/  $PATH_ARG
mv $PATH_ARG/$DIR $PATH_ARG/${COMPONENT_NAME,}

find $PATH_ARG/$COMPONENT_NAME/ -type f -exec sed -i -e 's/nameSpace/'$NAMESPACE'/g' {} \;
find $PATH_ARG/$COMPONENT_NAME/ -type f -exec sed -i -e 's/COMPONENT/'${COMPONENT_NAME^^}'/g' {} \;
find $PATH_ARG/$COMPONENT_NAME/ -type f -exec sed -i -e 's/Component/'${COMPONENT_NAME^}'/g' {} \;


sed -i 's/component/'${COMPONENT_NAME,}'/g' $PATH_ARG/${COMPONENT_NAME,}/CMakeLists.txt

mv $PATH_ARG/${COMPONENT_NAME,}/include/Component.h $PATH_ARG/${COMPONENT_NAME,}/include/${COMPONENT_NAME^}.h
mv $PATH_ARG/${COMPONENT_NAME,}/src/Component.cpp $PATH_ARG/${COMPONENT_NAME,}/src/${COMPONENT_NAME^}.cpp
mv $PATH_ARG/${COMPONENT_NAME,}/testsuites/ComponentTestSuite.h $PATH_ARG/${COMPONENT_NAME,}/testsuites/${COMPONENT_NAME^}TestSuite.h

echo $COMPONENT_NAME " files generated at " $PATH_ARG/$COMPONENT_NAME
