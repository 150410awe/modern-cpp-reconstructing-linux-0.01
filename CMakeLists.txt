cmake_minimum_required(VERSION 3.10)
project(linux)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(HEADER_PATH ${CMAKE_SOURCE_DIR}/include)

set(BUILD_SRC_FILES
	${SRC_PATH}/linux.cpp
)

add_executable(linux ${BUILD_SRC_FILES})
target_include_directories(linux PRIVATE ${HEADER_PATH})