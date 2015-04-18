#!/bin/bash

#PROJECT_NAME=$1
NAMESPACE=$1
COMPONENT_NAME=$2
PATH_ARG=$3


#echo $PROJECT_NAME
echo $NAMESPACE
echo $COMPONENT_NAME

cp -R component/  $PATH_ARG
mv $PATH_ARG/component $PATH_ARG/${COMPONENT_NAME,}

echo "generating MainModule"
#sed -i 's/component/'$COMPONENT_NAME'/g' $PATH_ARG/${COMPONENT_NAME,}/apps/MainModule.cpp
#sed -i 's/nameSpace/'$NAMESPACE'/g' $PATH_ARG/${COMPONENT_NAME,}/apps/MainModule.cpp

echo "Generating include"
#sed -i 's/Component/'$Component_NAME'/g' $PATH_ARG/${COMPONENT_NAME,}/include/*.h
#sed -i 's/COMPONENT/'${COMPONENT_NAME^^}'/g' $PATH_ARG/${COMPONENT_NAME,}/include/*.h
#sed -i 's/nameSpace/'$NAMESPACE'/g' $PATH_ARG/${COMPONENT_NAME,}/include/*.h

echo "Generating src"
#sed -i 's/Component/'$COMPONENT_NAME'/g' $PATH_ARG/${COMPONENT_NAME,}/src/*.cpp
#sed -i 's/nameSpace/'$NAMESPACE'/g' $PATH_ARG/${COMPONENT_NAME,}/src/*.cpp


echo "Generating TestSuite"
#sed -i 's/Component/'$COMPONENT_NAME'/g' $PATH_ARG/${COMPONENT_NAME,}/testsuites/*.h
#sed -i 's/COMPONENT/'${COMPONENT_NAME^^}'/g' $PATH_ARG/${COMPONENT_NAME,}/testsuites/*.h
#sed -i 's/nameSpace/'$NAMESPACE'/g' $PATH_ARG/${COMPONENT_NAME,}/testsuites/*.h

find $PATH_ARG/ -type f -exec sed -i -e 's/Component/'${COMPONENT_NAME^}'/g' {} \;
find $PATH_ARG/ -type f -exec sed -i -e 's/nameSpace/'$NAMESPACE'/g' {} \;
find $PATH_ARG/ -type f -exec sed -i -e 's/COMPONENT/'${COMPONENT_NAME^^}'/g' {} \;

echo "Generating CMAKE"
sed -i 's/component/'${COMPONENT_NAME,}'/g' $PATH_ARG/${COMPONENT_NAME,}/CMakeLists.txt


mv $PATH_ARG/${COMPONENT_NAME,}/include/Component.h $PATH_ARG/${COMPONENT_NAME,}/include/${COMPONENT_NAME^}.h
mv $PATH_ARG/${COMPONENT_NAME,}/src/Component.cpp $PATH_ARG/${COMPONENT_NAME,}/src/${COMPONENT_NAME^}.cpp
mv $PATH_ARG/${COMPONENT_NAME,}/testsuites/ComponentTestSuite.h $PATH_ARG/${COMPONENT_NAME,}/testsuites/${COMPONENT_NAME^}TestSuite.h
