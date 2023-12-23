cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(pong)

find_package(SFML COMPONENTS system window graphics audio REQUIRED)

add_executable(pong src/main.cpp src/player.cpp src/ball.cpp src/enemy.cpp)
target_link_libraries(pong PUBLIC sfml-system sfml-graphics sfml-window sfml-audio)
target_include_directories(pong PUBLIC include)
