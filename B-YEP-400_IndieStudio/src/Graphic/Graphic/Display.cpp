/*
** EPITECH PROJECT, 2021
** B-YEP_IndieStudio
** File description:
** Display
*/

#include "Graphic.hpp"
#include "Menu.hpp"
#include "DispGame.hpp"

static void Draw(irr::IrrlichtDevice *window) noexcept
{
    window->getSceneManager()->drawAll();
    window->getGUIEnvironment()->drawAll();
    window->getVideoDriver()->endScene();
}

int graph::Graphic::display(std::vector<std::vector<game::GameObject *>> map, std::vector<game::PlayerObject *> players) noexcept
{
    int ret = 0;

    _window->getVideoDriver()->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
    switch (_state) {
        case graph::stateGraph::CREDIT :
            displayStart();
            break;
        case graph::stateGraph::MENU :
            displayMenu();
            manageMenuButtons();
            break;
        case graph::stateGraph::GAME :
            displayGame(map, players);
            manageControls();
            break;
        case graph::stateGraph::PAUSE :
            displayPause();
            ret = managePauseButtons();
            break;
        case graph::stateGraph::OVER :
            ret = displayOver();
            break;
        default:
            break;
    }
    if (_receiver->isKeyDown(irr::KEY_ESCAPE) || _receiver->isButtonPressed(QUIT_BUTTON_ID))
        return -1;
    Draw(_window);
    return ret;
}

void graph::Graphic::displayMenu() noexcept
{
    if (!_menu)
        _menu = new graph::Menu(_window);
    if (_menu != nullptr)
        _menu->draw(_window);
    if (_menu->getState() == graph::menuState::HOW_TO_PLAY && _receiver->isKeyDown(irr::KEY_SPACE)) {
        _menu->displaySoundButtons(_musicState);
        _menu->setState(graph::menuState::CHOICE);
    }
}

void graph::Graphic::displayGame(std::vector<std::vector<game::GameObject *>> map, std::vector<game::PlayerObject *> players) noexcept
{
    if (!_game)
        _game = new graph::Game(map, players, _window, _playerNumber);
    if (_game != nullptr)
        _game->draw(_window, players, map);
}

void graph::Graphic::displayPause() noexcept
{
    if (_game != nullptr)
        _game->pause(_window);
}

void graph::Graphic::displayStart() noexcept
{
    _window->getVideoDriver()->draw2DImage(_texture, irr::core::position2d<irr::s32>(0, 0), 
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr,
        irr::video::SColor(255, 255, 255, 255), true);
    if (_receiver->isKeyDown(irr::KEY_SPACE))
        _state = graph::stateGraph::MENU;
}

int graph::Graphic::displayOver() noexcept
{
    std::string winner;

    _game->disableDraw();
    for (auto i = 0; i != _game->getPlayers().size(); ++i) {
        if (_game->getPlayers()[i] != nullptr)
            winner = _game->getPlayers()[i]->getName();
    }
    
    _window->getVideoDriver()->draw2DImage(_gameOver[winner], irr::core::position2d<irr::s32>(0, 0), 
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr,
        irr::video::SColor(255, 255, 255, 255), true);
    if (_receiver->isKeyDown(irr::KEY_SPACE)) {
        if (_game != nullptr) {
            delete(_game);
            _game = nullptr;
        }
        return -2;
    }
    return 0;
}