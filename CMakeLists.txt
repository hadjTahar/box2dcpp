cmake_minimum_required(VERSION 3.16)
project(box2cpp LANGUAGES CXX)



### Add file sources
### ---------------
file(GLOB_RECURSE SAMPLE_SRC_FILES *.h *.cpp)

add_library(box2cpp STATIC ${SAMPLE_SRC_FILES} )
target_compile_features(box2cpp PUBLIC cxx_std_20)


target_include_directories(box2cpp PUBLIC  "${CMAKE_SOURCE_DIR}/vendors/box2cpp/include")

# Box 2D
target_include_directories(box2cpp PUBLIC  "${CMAKE_SOURCE_DIR}/vendors/box2d/include")
target_link_libraries( box2cpp PUBLIC box2d )


