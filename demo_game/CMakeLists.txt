






cmake_minimum_required(VERSION 3.10)

project(Game_test)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp src/Game.cpp "src/StateManager/StateManager.cpp" 
								"src/StateManager/State.cpp" "src/Button.h")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)