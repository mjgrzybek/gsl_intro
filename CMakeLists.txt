cmake_minimum_required(VERSION 3.5)

project(GSL_intro)

set(CMAKE_CXX_STANDARD 14)

set(GSL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ext/gsl-lite/include/)
include_directories(${GSL_INCLUDE_DIR})

set(SRC_LIST
	main.cpp
	not_null.cpp
	owner.cpp
	span.cpp
	narrow_cast.cpp
)

set(APP_NAME gsl_examples)

add_executable(${APP_NAME} ${SRC_LIST})
target_link_libraries(${APP_NAME} gtest gtest_main pthread)
