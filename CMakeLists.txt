cmake_minimum_required(VERSION 3.0)

SET(CMAKE_STATIC_LIBRARY_PREFIX "")
SET(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")

include(cmake/stdex_download.cmake)

SET(THIRDPARTY_DIR ${CMAKE_SOURCE_DIR}/dependencies)

set(STDEX_EXTERNAL_BUILD ON CACHE BOOL "STDEX_EXTERNAL_BUILD" FORCE)

PROJECT(pycpp)

MESSAGE(${CMAKE_CURRENT_SOURCE_DIR}/include/pycpp/)
file(GLOB files_headers_pycpp ${CMAKE_CURRENT_SOURCE_DIR}/include/pycpp/*.hpp)
file(GLOB files_sources_pycpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(PYCPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES( ${PYCPP_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( ${STDEX_INCLUDE_DIR} )

ADD_LIBRARY( ${PROJECT_NAME} ${files_headers_pycpp} ${files_sources_pycpp} )

add_dependencies(${PROJECT_NAME} stdex_download)

ADD_SUBDIRECTORY(test/test1)