cmake_minimum_required(VERSION 3.17)
project(OOP_indie_studio_2020)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

include_directories(cmake_modules)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/include/Graphic/SFML")

set(PATH_MODULE_Irrlicht "${CMAKE_MODULE_PATH}/IrrLicht")
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/Irrlicht")
include_directories(cmake_modules/Irrlicht)
include_directories(cmake_modules/Irrlicht/include)
find_package(Irrlicht REQUIRED)
link_libraries(${Irrlicht_LIBRARIES})

include_directories(include)
include_directories(cmake_modules/include/SFML)
include_directories(include/Graphic)
include_directories(include/Game)
include_directories(include/Graphic/SFML)
include_directories(include/Graphic/Irrlicht)

link_directories(include/Graphic/SFML/lib)

add_executable(bomberman
            include/Indie.hpp
            include/EnumGraph.hpp
            src/Main.cpp
            src/Graphic/Graphic/Controls.cpp
            src/Graphic/Graphic/Display.cpp
            src/Graphic/Graphic/Graphic.cpp
            src/Graphic/Menu.cpp
            src/Graphic/EventReceiver.cpp
            src/Graphic/DispGame/DispGame.cpp
            src/Graphic/DispGame/Create.cpp
            src/Graphic/DispGame/Buttons.cpp
            src/Graphic/DispGame/Display.cpp
            src/Graphic/DispGame/Update.cpp
            src/Graphic/Player.cpp
            src/Game/Game.cpp
            src/Game/Bomb.cpp
            src/Game/Convert.cpp
            src/Game/GameObject.cpp
            src/Game/Map.cpp
            src/Game/Player.cpp
            src/Game/PlayerObject.cpp
            src/Game/Save.cpp
)

target_link_libraries(bomberman ${Irrlicht_LIBRARIES} sfml-audio boost_system boost_timer boost_chrono rt)

if (!WIN32)
    target_compile_options(bomberman PRIVATE -g3)
endif()

get_target_property(INDIE_EXE_PATH bomberman CMAKE_RUNTIME_OUTPUT_DIRECTORY)