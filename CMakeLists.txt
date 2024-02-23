cmake_minimum_required(VERSION 3.10) 

project(MyProject)  

file(GLOB SOURCE_FILES ./src/*.cpp)

file(GLOB HEADER_FILES ./src/*.h)

add_executable(MyExecutable ${SOURCE_FILES} ${HEADER_FILES})
