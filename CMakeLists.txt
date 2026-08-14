#file scritto da Francesco Barban

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

project(tutor_autostradale)

include_directories(simulatore/include tutor/include)

#primo eseguibile 

add_library(simulator_lib STATIC simulatore/src/driveTracker.cpp simulatore/src/highway.cpp simulatore/src/randomFunc.cpp simulatore/src/traffic.cpp simulatore/src/vehicle.cpp)

add_executable(simulator simulatore/src/simulatore.cpp)

target_link_libraries(simulator simulator_lib)

install(TARGETS simulator_lib LIBRARY DESTINATION lib INCLUDES DESTINATION include)

#secondo eseguibile

add_library(tutor_lib STATIC tutor/src/timeline.cpp tutor/src/userFuncs.cpp tutor/src/varcoRecords.cpp tutor/src/vehicleRecords.cpp simulatore/src/highway.cpp)

add_executable(tutor tutor/src/tutor.cpp)

target_link_libraries(tutor tutor_lib)

install(TARGETS tutor_lib LIBRARY DESTINATION lib INCLUDES DESTINATION include)

#flag
set(CMAKE_CXX_FLAGS "-O2") 