/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** GraphMain
*/

#include <iostream>
#include "Graphic.hpp"
#include "Menu.hpp"
#include "DispGame.hpp"

graph::Graphic::Graphic() noexcept
{
    _window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920,1080),
        16, false, false, false);

    if (!_window) {
        std::cerr << "Error: Couldn't open a window" << std::endl;
        return;
    }
    _window->setWindowCaption(L"Indie Studio");
    _receiver = new EventReceiver(_window, *this);
    _window->setEventReceiver(_receiver);
    _state = graph::stateGraph::CREDIT;
    _music = new sf::Music;
    _music->openFromFile("assets/music/music.ogg");
    _music->play();
    _menu = nullptr;
    _game = nullptr;
    _texture = _window->getVideoDriver()->getTexture("assets/ground/credit.png");
    _playerNumber = 0;
    _direction1 = game::Direction::STAY;
    _direction2 = game::Direction::STAY;
    _musicState = true;
    _save = false;
    _load = false;
    createGameOverScreens();
}

graph::Graphic::~Graphic()
{
    _window->getSceneManager()->clear();
    _music->pause();
    _music->stop();
    delete(_music);
    delete(_receiver);
    delete(_menu);
    if (_game != nullptr)
        delete(_game);
    _window->getVideoDriver()->removeAllTextures();
    _window->closeDevice();
}

void graph::Graphic::createGameOverScreens() noexcept
{
    _gameOver.emplace(std::string("player 1"), _window->getVideoDriver()->getTexture("assets/ground/player_one_win.png"));
    _gameOver.emplace(std::string("player 2"), _window->getVideoDriver()->getTexture("assets/ground/player_two_win.png"));
    _gameOver.emplace(std::string("ai 1"), _window->getVideoDriver()->getTexture("assets/ground/ai_one_win.png"));
    _gameOver.emplace(std::string("ai 2"), _window->getVideoDriver()->getTexture("assets/ground/ai_two_win.png"));
    _gameOver.emplace(std::string("ai 3"), _window->getVideoDriver()->getTexture("assets/ground/ai_three_win.png"));
}

bool graph::Graphic::getIsOpen() const noexcept
{
    return _window->run();
}

game::Direction graph::Graphic::getDirectionPlayerOne() const noexcept
{
    return _direction1;
}

game::Direction graph::Graphic::getDirectionPlayerTwo() const noexcept
{
    return _direction2;
}

bool graph::Graphic::getActionPlayerOne() const noexcept
{
    return _action1;
}

bool graph::Graphic::getActionPlayerTwo() const noexcept
{
    return _action2;
}

graph::Game *graph::Graphic::getGame() const noexcept
{
    return _game;
}

graph::Menu *graph::Graphic::getMenu() const noexcept
{
    return _menu;
}

int graph::Graphic::getPlayerNumber() const noexcept
{
    return _playerNumber;
}

graph::stateGraph graph::Graphic::getState() const noexcept
{
    return _state;
}

void graph::Graphic::setNewPlayerPositions(int id, std::vector<game::PlayerObject *> players, game::Direction direction) noexcept
{
    _game->setNewPlayerPositions(id, players, direction, _playerNumber);
}

void graph::Graphic::setPlayerNumber(int nbr) noexcept
{
    _playerNumber = nbr;
}

bool graph::Graphic::getSave() const noexcept
{
    return _save;
}

bool graph::Graphic::getLoad() const noexcept
{
    return _load;
}

void graph::Graphic::setLoad(bool load) noexcept
{
    _load = load;
}

void graph::Graphic::setSave(bool save) noexcept
{
    _save = save;
}

void graph::Graphic::setState(graph::stateGraph state) noexcept
{
    _state = state;
}