cmake_minimum_required(VERSION 3.14)

# Define o padrão de linguagem para C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(guerra-dos-mundos)

add_executable(guerra-dos-mundos main.cpp Motor/Game.cpp Personagem/Player.cpp GeradorMapa/TileGenerator.cpp GeradorMapa/TileBlock.cpp Enemy.cpp Estados/MainMenuState.cpp Fases/Fase1.cpp Estados/GameState.cpp Estados/GameOverState.cpp Fases/Fase.cpp Animacao/Animacao.cpp Personagem/HealthBar.cpp Colisao/Collider.cpp Personagem/Soldado.cpp Fabrica/FabricaJogador.cpp Personagem/Coletor.cpp Personagem/Aereo.cpp Interface/Botao.cpp GeradorMapa/FonteEnergia.cpp Interface/BarraMensagem/BarraMensagem.cpp Interface/PainelControle/PainelControle.cpp)

install(TARGETS guerra-dos-mundos RUNTIME DESTINATION bin)
 add_custom_command(
    TARGET guerra-dos-mundos POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/Recursos $<TARGET_FILE_DIR:guerra-dos-mundos>/Recursos/
 )

target_link_libraries(
    guerra-dos-mundos
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
    -lsfml-audio
)
