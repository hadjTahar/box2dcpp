cmake_minimum_required(VERSION 3.16)
project(box2dcpp LANGUAGES CXX)



### Add file sources
### ---------------
file(GLOB_RECURSE SAMPLE_SRC_FILES *.h *.cpp)

add_library(box2dcpp STATIC ${SAMPLE_SRC_FILES} )
target_compile_features(box2dcpp PUBLIC cxx_std_20)


target_include_directories(box2dcpp PUBLIC  "${CMAKE_SOURCE_DIR}/vendors/box2dcpp/include")

# Box 2D
target_include_directories(box2dcpp PUBLIC  "${CMAKE_SOURCE_DIR}/vendors/box2d/include")
target_link_libraries( box2dcpp PUBLIC box2d )


