#
# This software is open source. Please see COPYING and AUTHORS for further information.
#
PROJECT (libmsv)
# Include directories from core.
INCLUDE_DIRECTORIES (${libopendavinci_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES (include)
# Recipe for building libmsv.
FILE(GLOB_RECURSE libmsv-sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
ADD_LIBRARY (msv STATIC ${libmsv-sources})
# Recipe for installing libmsv.
INSTALL(TARGETS msv DESTINATION lib)
# Install header files.
INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/" DESTINATION include/libmsv)
IF(CXXTEST_FOUND)
FILE(GLOB libmsv-testsuites "${CMAKE_CURRENT_SOURCE_DIR}/testsuites/*.h")
FOREACH(testsuite ${libmsv-testsuites})
    STRING(REPLACE "/" ";" testsuite-list ${testsuite})
    LIST(LENGTH testsuite-list len)
    MATH(EXPR lastItem "${len}-1")
    LIST(GET testsuite-list "${lastItem}" testsuite-short)
	    CXXTEST_ADD_TEST(${testsuite-short}-TestSuite ${testsuite-short}-TestSuite.cpp ${testsuite})
	    TARGET_LINK_LIBRARIES(${testsuite-short}-TestSuite msv ${OPENDAVINCI_LIBS} ${LIBS})
    ENDFOREACH()
ENDIF(CXXTEST_FOUND)
