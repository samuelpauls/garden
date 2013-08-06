# Copyright 2013, Samuel Pauls

cmake_minimum_required (VERSION 2.8)

project ("garden" CXX)

add_executable (garden main.cpp)

target_link_libraries (garden sfml-window sfml-system GL)
