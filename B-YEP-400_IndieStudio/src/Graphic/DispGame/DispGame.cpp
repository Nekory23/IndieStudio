/*
** EPITECH PROJECT, 2021
** B-YEP_indie
** File description:
** DispGame
*/

#include "DispGame.hpp"

graph::Game::Game(std::vector<std::vector<game::GameObject *>> map, std::vector<game::PlayerObject *> players, irr::IrrlichtDevice *window, int nbr) noexcept
{
    loadTextures(window);
    createBlock(map, window);
    createPlayers(players, window, nbr);
    createPauseButtons(window);
    setScene(window);
}

graph::Game::~Game()
{
    for (auto i = 0; i != _players.size(); ++i)
        delete(_players[i]);
    _players.clear();
}

void graph::Game::loadTextures(irr::IrrlichtDevice *window) noexcept
{
    _textures.emplace(std::string("resume button"), window->getVideoDriver()->getTexture("assets/buttons/resume_button.png"));
    _textures.emplace(std::string("quit_game button"), window->getVideoDriver()->getTexture("assets/buttons/quit_button.png"));
    _textures.emplace(std::string("save button"), window->getVideoDriver()->getTexture("assets/buttons/save_button.png"));
  
    _textures.emplace(std::string("redBricks"), window->getVideoDriver()->getTexture("assets/blocks/RedBricks.bmp"));
    _textures.emplace(std::string("woodenFloor"), window->getVideoDriver()->getTexture("assets/blocks/WoodenFloor.bmp"));
    _textures.emplace(std::string("grass"), window->getVideoDriver()->getTexture("assets/ground/grass.jpg"));

    _textures.emplace(std::string("bomb"), window->getVideoDriver()->getTexture("assets/blocks/tnt.jpg"));
    _textures.emplace(std::string("explosion"), window->getVideoDriver()->getTexture("assets/blocks/explosion.jpg"));

    _textures.emplace(std::string("bombUp"), window->getVideoDriver()->getTexture("assets/blocks/BombUp.jpg"));
    _textures.emplace(std::string("speedUp"), window->getVideoDriver()->getTexture("assets/blocks/SpeedUp.png"));
    _textures.emplace(std::string("fireUp"), window->getVideoDriver()->getTexture("assets/blocks/FireUp.jpg"));
    _textures.emplace(std::string("wallPass"), window->getVideoDriver()->getTexture("assets/blocks/WallPass.png"));
    
    _textures.emplace(std::string("gameBackground"), window->getVideoDriver()->getTexture("assets/ground/gameBackground.jpg"));
    _textures.emplace(std::string("pause"), window->getVideoDriver()->getTexture("assets/ground/pause.png"));
}

void graph::Game::setScene(irr::IrrlichtDevice *window) noexcept
{
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(20, 0, -35), irr::video::SColorf(2.0f, 2.0f, 1.0f), irr::s32(50.0f));
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(20, -60, -35), irr::video::SColorf(1.0f, 1.0f, 1.0f), irr::s32(50.0f));

    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(65, 0, -35), irr::video::SColorf(2.0f, 2.0f, 1.0f), irr::s32(50.0f));
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(65, -60, -35), irr::video::SColorf(1.0f, 1.0f, 1.0f), irr::s32(50.0f));

    window->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(35, -38, -38), irr::core::vector3df(35, -19, 0));
}

std::vector<std::vector<irr::scene::ISceneNode *>> graph::Game::getCubes() const noexcept
{
    return _cubes;
}

std::vector<std::vector<irr::scene::ISceneNode *>> graph::Game::getFloor() const noexcept
{
    return _floor;
}

std::vector<graph::Player *> graph::Game::getPlayers() const noexcept
{
    return _players;
}