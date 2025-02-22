cmake_minimum_required(VERSION 3.4)
project(tool)

aux_source_directory(./calibration CAL_SRC)
aux_source_directory(./debug DEBUG_SRC)

add_library(tool STATIC ${CAL_SRC} ${DEBUG_SRC})
