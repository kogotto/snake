
cmake_minimum_required(VERSION 3.17)

project(snake)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(external EXCLUDE_FROM_ALL)

add_executable(
    snake

    main.cpp

    Machine.cpp
    MainMenuMachine.cpp
    GameMachine.cpp
)

include_directories(".")

target_link_libraries(
    snake

    PRIVATE SDL3::SDL3
)
