# Sets the CMAKE version
cmake_minimum_required(VERSION 3.9)

# Set c++11 as the standrad
set (CMAKE_CXX_STANDARD 11)

# Name of the project
project(quintifio)

# Find the boost library
find_package(Boost)
# Include the boost include directory
include_directories(
    ${Boost_INCLUDE_DIRS}
)

# Set to compile all .cpp files found in the directory source
file(GLOB SOURCES "source/*.cpp")

# Name of executable
add_executable(quin ${SOURCES})
# Link to the boos library
target_link_libraries(quin
  ${Boost_LIBRARIES}
)