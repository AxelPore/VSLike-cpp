include(GenerateExportHeader)

add_library(common SHARED
    common/button.cpp
    common/bg.cpp
    common/text.cpp
  )

target_link_libraries(
    common PUBLIC
    sfml-system sfml-window sfml-graphics
)

target_include_directories(
    common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)   

set_target_properties(common PROPERTIES DEFINE_SYMBOL COMMON_EXPORTS)
generate_export_header(common
    BASE_NAME        COMMON
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/common_export.h
)

add_library(game SHARED
    game/game.cpp
    game/player.cpp 
    game/bouleDeFeu.cpp)

target_link_libraries(
    game PUBLIC
    sfml-system sfml-window sfml-graphics common
)

target_include_directories(
    game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)   

set_target_properties(game PROPERTIES DEFINE_SYMBOL GAME_EXPORTS)
generate_export_header(game
    BASE_NAME        GAME
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/game_export.h
)

add_library(menu SHARED
    menu/menu.cpp
)

target_link_libraries(
    menu PUBLIC
    sfml-system sfml-window sfml-graphics common game
)

target_include_directories(
    menu PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(menu PROPERTIES DEFINE_SYMBOL MENU_EXPORTS)
generate_export_header(menu
    BASE_NAME        MENU
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/menu_export.h
)

add_executable(Vampire_Survivor_Like main.cpp)
target_link_libraries(Vampire_Survivor_Like PUBLIC 
sfml-system sfml-window sfml-graphics menu
)