#
# Mini-Smart-Vehicles.
#
# This software is open source. Please see COPYING and AUTHORS for further information.
#

PROJECT (component)

# Include directories from core.
INCLUDE_DIRECTORIES (${libopendavinci_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES (${libdata_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES (include)

# Recipe for building "component".
FILE(GLOB_RECURSE component-sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
ADD_LIBRARY (componentlib STATIC ${component-sources})
ADD_EXECUTABLE (component "${CMAKE_CURRENT_SOURCE_DIR}/apps/MainModule.cpp")
TARGET_LINK_LIBRARIES (component componentlib ${DATA_LIBS} ${OPENDAVINCI_LIBS} ${LIBS}) 

# Recipe for installing "component".
INSTALL(TARGETS component RUNTIME DESTINATION bin) 

# Enable CxxTest for all available testsuites.
IF(CXXTEST_FOUND)
    FILE(GLOB component-testsuites "${CMAKE_CURRENT_SOURCE_DIR}/testsuites/*.h")
    
    FOREACH(testsuite ${component-testsuites})
        STRING(REPLACE "/" ";" testsuite-list ${testsuite})

        LIST(LENGTH testsuite-list len)
        MATH(EXPR lastItem "${len}-1")
        LIST(GET testsuite-list "${lastItem}" testsuite-short)

	    CXXTEST_ADD_TEST(${testsuite-short}-TestSuite ${testsuite-short}-TestSuite.cpp ${testsuite})
	    TARGET_LINK_LIBRARIES(${testsuite-short}-TestSuite componentlib ${DATA_LIBS} ${OPENDAVINCI_LIBS} ${LIBS})
    ENDFOREACH()
ENDIF(CXXTEST_FOUND)
