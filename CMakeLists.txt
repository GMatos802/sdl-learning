cmake_minimum_required(VERSION 3.10)
project(MeuJogoSDL)

find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(programa src/class2.cpp)

target_link_libraries(programa ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
