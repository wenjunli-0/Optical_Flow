cmake_minimum_required(VERSION 3.12)
project(DBSCAN)

set(CMAKE_CXX_STANDARD 14)


#find_library
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(DBSCAN main.cpp dbscan.cpp)
add_executable(draw_bounding_box draw_bounding_box.cpp)


#link_targets
target_link_libraries(draw_bounding_box ${OpenCV_LIBS})



#LIBS += CoreFoundation