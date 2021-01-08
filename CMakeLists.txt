cmake_minimum_required(VERSION 3.17)

project(OpenCVCMakeSample
        VERSION 0.1.0
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Find OpenCV on the system and add it to the project
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Add include folder for this project's headers
include_directories(include)

# Run CMakeLists.txt in ./src
add_subdirectory(src)
