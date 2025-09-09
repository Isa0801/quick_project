cmake_minimum_required(VERSION 3.27)

project(robot_warehouse)

# package. side note, FetchContent is function cool, I will need to look into later (which might be never xD)
find_package(SDL2 REQUIRED)

# set path for artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories("${PROJECT_SOURCE_DIR}/inc")

# becuase I am lazy to create proper cmake struct, we want it aaalllllll
file(GLOB
  CPP_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(robot_warehouse ${CPP_SOURCES})

target_link_libraries(robot_warehouse PRIVATE SDL2::SDL2)


