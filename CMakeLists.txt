cmake_minimum_required(VERSION 3.14)

# Define o padrão de linguagem para C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(guerra-dos-mundos)

add_executable(guerra-dos-mundos main.cpp Game.cpp Player.cpp TileGenerator.cpp TileBlock.cpp Enemy.cpp UI/MainMenuState.cpp UI/PlayState.cpp)

install(TARGETS guerra-dos-mundos RUNTIME DESTINATION bin)

target_link_libraries(
    guerra-dos-mundos
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
)
