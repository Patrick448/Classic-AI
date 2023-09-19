cmake_minimum_required(VERSION 3.16.3)
project(ClassicAI)

set(CMAKE_CXX_STANDARD 14)
#SET(CMAKE_CXX_FLAGS "-O3")
#SET(CMAKE_C_FLAGS "-O3")
file(GLOB source_cpp src/*.cpp)
file(GLOB source_h include/*.h)
file(GLOB source_c src/*.c)


find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(include)

add_executable(ClassicAI ${source_cpp} ${source_c} src/main.cpp)

add_executable(test ${source_cpp} ${source_c})
target_link_libraries(test PUBLIC
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
