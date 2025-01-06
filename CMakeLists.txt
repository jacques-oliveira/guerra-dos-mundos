cmake_minimum_required(VERSION 3.0)

project(guerra-dos-mundos)

add_executable(guerra-dos-mundos main.cpp Game.cpp Player.cpp TileGenerator.cpp TileBlock.cpp)

install(TARGETS guerra-dos-mundos RUNTIME DESTINATION bin)

target_link_libraries(
    guerra-dos-mundos
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
)
