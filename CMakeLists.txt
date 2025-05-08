








cmake_minimum_required(VERSION 3.10)

project(Test)

set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

find_package(SDL2 REQUIRED)

set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(Engine)
add_subdirectory(Engine)





add_executable(${PROJECT_NAME}  main.cpp)

target_link_libraries(${PROJECT_NAME} Engine)

# Copy assets into app bundle
# For development:
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${PROJECT_SOURCE_DIR}/SDL2
  $<TARGET_FILE_DIR:${PROJECT_NAME}>)