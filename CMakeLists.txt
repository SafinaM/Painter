cmake_minimum_required(VERSION 2.8)

project(Painter)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/rlutil" "${CMAKE_BINARY_DIR}/rlutil")

set(SOURCES
	Painter.cpp
	PainterImpl.cpp
	Figure.cpp
	BoardBase.cpp
	)

set(HEADERS
	Painter.h
	PainterImpl.h
	BoardBase.h
	Figure.h
	)

add_library(Core STATIC ${SOURCES} ${HEADERS})
target_include_directories(Core PUBLIC rlutil)