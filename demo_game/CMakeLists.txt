






cmake_minimum_required(VERSION 3.10)

project(Game_test)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp src/Game.cpp "src/StateManager/StateMachine.cpp" 
	"src/StateManager/State.cpp" "src/Button.h" "src/Button.cpp" "src/ECS/EntityManager.h" 
	"src/ECS/ComponentManager.h" "src/ECS/Components.h" "src/Grid.h" "src/Fruit.h")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)