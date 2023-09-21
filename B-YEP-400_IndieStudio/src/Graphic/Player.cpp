/*
** EPITECH PROJECT, 2021
** B-YEP_indie
** File description:
** Player
*/

#include "DispGame.hpp"

graph::Player::Player(irr::IrrlichtDevice *_window, int rotation, int posx, int posy, std::string name) noexcept
{
    _frameDeltaTime = 0.020;
    _playerMesh = _window->getSceneManager()->getMesh("assets/models/Bomberman.b3d");
    _playerNode = _window->getSceneManager()->addAnimatedMeshSceneNode(_playerMesh);
    _playerNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _playerNode->setMaterialTexture(0, _window->getVideoDriver()->getTexture("assets/models/Bomberman.png"));
    _playerNode->setRotation(irr::core::vector3df(-90, 0, rotation));
    _playerNode->setPosition(irr::core::vector3df(posx, posy, 0));
    _playerName = name;
}

irr::scene::IAnimatedMeshSceneNode *graph::Player::getNode() const noexcept
{
    return _playerNode;
}

std::string graph::Player::getName() const noexcept
{
    return _playerName;
}