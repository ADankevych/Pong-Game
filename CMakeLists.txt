cmake_minimum_required(VERSION 3.28)
project(Pong_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pong_Game main.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(Pong_Game PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)