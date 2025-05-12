






cmake_minimum_required(VERSION 3.10)

project(Engine)

find_package(SDL2 REQUIRED)

include_directories(include)

add_library(${PROJECT_NAME} SHARED src/console.cpp "src/Game.cpp" 
"include/Game.h" "src/ECS/ECS.cpp"
"include/ECS/ComponentManager.h"  "include/ECS/SystemManager.h"  "include/StateManager/StateManager.h"
src/StateManager/State.cpp "include/ECS/Types.h" "include/ECS/System.h" "Timer.h" "Timer.cpp")
 


target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_EXPORTS)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)