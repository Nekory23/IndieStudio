/*
** EPITECH PROJECT, 2021
** B-YEP_IndieStudio
** File description:
** Display
*/

#include "DispGame.hpp"

void graph::Game::draw(irr::IrrlichtDevice *window, std::vector<game::PlayerObject *> players, std::vector<std::vector<game::GameObject *>> map) noexcept
{
    updateMap(map, window);
    updatePlayers(players);
    enableDraw();
    window->getVideoDriver()->draw2DImage(_textures["gameBackground"], irr::core::position2d<irr::s32>(0, 0), 
                                            irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, 
                                            irr::video::SColor(255, 255, 255, 255), true);
}

void graph::Game::pause(irr::IrrlichtDevice *window) noexcept
{
    enablePauseButtons();
    window->getVideoDriver()->draw2DImage(_textures["pause"], irr::core::position2d<irr::s32>(0, 0), 
                                            irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, 
                                            irr::video::SColor(255, 255, 255, 255), true);
}

void graph::Game::disableDraw() noexcept
{
    for (auto i = 0; i != _cubes.size(); ++i)
        for (auto j = 0; j != _cubes[i].size(); ++j) {
            if (!_cubes[i][j])
                continue;
            _cubes[i][j]->setVisible(false);
        }
    for (auto i = 0; i != _floor.size(); ++i)
        for (auto j = 0; j != _floor[i].size(); ++j) {
            if (!_floor[i][j])
                continue;
            _floor[i][j]->setVisible(false);
        }
    for (auto i = 0; i != _players.size(); ++i) {
        if (!_players[i])
            continue;
        _players[i]->getNode()->setVisible(false);
    }
}

void graph::Game::enableDraw() noexcept
{
    for (auto i = 0; i != _cubes.size(); ++i)
        for (auto j = 0; j != _cubes[i].size(); ++j) {
            if (!_cubes[i][j])
                continue;
            _cubes[i][j]->setVisible(true);
        }
    for (auto i = 0; i != _floor.size(); ++i)
        for (auto j = 0; j != _floor[i].size(); ++j) {
            if (!_floor[i][j])
                continue;
            _floor[i][j]->setVisible(true);
        }
    for (auto i = 0; i != _players.size(); ++i) {
        if (!_players[i])
            continue;
        _players[i]->getNode()->setVisible(true);
    }
}