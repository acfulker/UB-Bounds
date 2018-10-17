cmake_minimum_required(VERSION 3.10)
project(Boundaries)

set(CMAKE_CXX_STANDARD 11)

add_executable(Boundaries main.cpp Box.cpp Box.h ../World.cpp ../World.h ../Agent.cpp ../Agent.h Agent.cpp Agent.h World.cpp World.h)