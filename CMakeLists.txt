cmake_minimum_required(VERSION 3.25)

project(ImageDisplay)

set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    src/Main.cpp
    src/FeatureExtractor.cpp
    src/Matcher.cpp
    src/Assembler.cpp
)

# OpenCV
set(OpenCV_DIR "C:/opencv")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(MyImageApplication ${SOURCES})

target_link_libraries(MyImageApplication ${OpenCV_LIBS})
