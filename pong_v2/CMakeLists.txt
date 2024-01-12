cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(pong_v2)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(SDL2)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})

find_package(SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_ttf_INCLUDE_DIRS})
