cmake_minimum_required(VERSION 3.10)
project(Boundaries)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
#message("${CMAKE_MODULE_PATH}")

find_package(LibXML++ REQUIRED)
include_directories(${LibXML++_INCLUDE_DIRS})
set(LIBS ${LIBS} ${LibXML++_LIBRARIES})

add_executable(Boundaries main.cpp Box.cpp Box.h ../World.cpp ../World.h ../Agent.cpp ../Agent.h Agent.cpp Agent.h World.cpp World.h Coord.cpp Coord.h)
target_link_libraries(Boundaries ${LibXML++_LIBRARIES})