# Copyright 2013, Samuel Pauls

cmake_minimum_required (VERSION 2.8)

project ("flowers" CXX)

add_executable (flowers main.cpp)

target_link_libraries (flowers sfml-window sfml-system GL)
