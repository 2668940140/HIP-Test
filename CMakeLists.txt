cmake_minimum_required(VERSION 3.21)

list(APPEND CMAKE_PREFIX_PATH "/opt/rocm/lib/cmake")

project(Test LANGUAGES CXX HIP)

# Find HIP package
find_package(HIP REQUIRED)

# Define the executable
add_executable(Test main.cpp)

set_source_files_properties(main.cpp PROPERTIES LANGUAGE HIP)

target_include_directories(Test PRIVATE /opt/rocm/include/*)

# Link any necessary libraries (if any)
target_link_libraries(Test hip::host hip::device)