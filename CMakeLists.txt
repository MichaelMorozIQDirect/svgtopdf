cmake_minimum_required(VERSION 3.5.0)

project(svgtopdf VERSION 1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(Haru REQUIRED)

add_library(nanosvg STATIC svgtopdf/nanosvg.cpp)

target_include_directories(nanosvg PRIVATE svgtopdf)

add_executable(svgtopdf
	svgtopdf/SvgConverter.cpp
	svgtopdf/main.cpp)


target_link_libraries(svgtopdf PRIVATE Haru::hpdf nanosvg)

target_include_directories(svgtopdf PRIVATE svgtopdf)
