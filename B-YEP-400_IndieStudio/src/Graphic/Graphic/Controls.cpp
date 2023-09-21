/*
** EPITECH PROJECT, 2021
** B-YEP_IndieStudio
** File description:
** Controls
*/

#include "Graphic.hpp"
#include "DispGame.hpp"
#include "Menu.hpp"

int graph::Graphic::manageMenuButtons() noexcept
{
    if (_receiver->isButtonPressed(NEW_BUTTON_ID))
        _menu->setState(graph::menuState::CHOICE);
    if (_receiver->isButtonPressed(HTP_BUTTON_ID))
        _menu->setState(graph::menuState::HOW_TO_PLAY);
    if (_receiver->isButtonPressed(SOUND_OFF_BUTTON_ID)) {
        _music->openFromFile("assets/music/music.ogg");
        _music->play();
        _menu->displaySoundButtons(true);
        _musicState = true;
    }
    if (_receiver->isButtonPressed(SOUND_ON_BUTTON_ID)) {
        _music->stop();
        _menu->displaySoundButtons(false);
        _musicState = false;
    }
    if (_receiver->isButtonPressed(BACK_BUTTON_ID))
        _menu->setState(graph::menuState::MAIN);
    if (_receiver->isButtonPressed(ONE_BUTTON_ID)) {
        _menu->disableSoundButtons();
        _menu->disableMainButtons();
        _menu->disableChoiceButtons();
        _playerNumber = 1;
        _state = GAME;
        _music->stop();
        if (_musicState) {
            _music->openFromFile("assets/music/bomber_music.ogg");
            _music->play();
        }
    }
    if (_receiver->isButtonPressed(TWO_BUTTON_ID)) {
        _menu->disableSoundButtons();
        _menu->disableMainButtons();
        _menu->disableChoiceButtons();
        _playerNumber = 2;
        _state = GAME;
        _music->stop();
        if (_musicState) {
            _music->openFromFile("assets/music/bomber_music.ogg");
            _music->play();
        }
    }
    if (_receiver->isButtonPressed(LOAD_BUTTON_ID)) {
        if (_saveFile == true) {
            _load = true;
            _state = GAME;
            _menu->disableSoundButtons();
            _menu->disableMainButtons();
            _menu->disableChoiceButtons();
            _music->stop();
            if (_musicState) {
                _music->openFromFile("assets/music/bomber_music.ogg");
                _music->play();
            }
        }
    }
    return 0;
}

int graph::Graphic::managePauseButtons() noexcept
{
    if (_receiver->isButtonPressed(RESUME_BUTTON_ID)) {
        _state = GAME;
        _game->disablePauseButtons();
    }
    if (_receiver->isButtonPressed(QUIT_GAME_BUTTON_ID)) {
        _menu->displaySoundButtons(_musicState);
        _state = MENU;
        _game->disablePauseButtons();
        _menu->setState(graph::menuState::MAIN);
        _music->stop();
        if (_musicState) {
            _music->openFromFile("assets/music/music.ogg");
            _music->play();
        }
        _game->disableDraw();
        _window->getSceneManager()->clear();
        delete(_game);
        _game = nullptr;
        return -2;
    }
    if (_receiver->isButtonPressed(SAVE_AND_QUIT_BUTTON_ID)) {
        _save = true;
        _saveFile = true;
        _menu->displaySoundButtons(_musicState);
        _state = MENU;
        _game->disablePauseButtons();
        _menu->setState(graph::menuState::MAIN);
        _music->stop();
        if (_musicState) {
            _music->openFromFile("assets/music/music.ogg");
            _music->play();
        }
        _game->disableDraw();
        _window->getSceneManager()->clear();
        delete(_game);
        _game = nullptr;
        return -3;
    }
    return 0;
}

int graph::Graphic::manageControls() noexcept
{
    if (_playerNumber == 0)
        return 0;
    if (_receiver->isKeyDown(irr::KEY_SPACE)) {
        _state = PAUSE;
        return 0;
    }

    _action1 = false;
    _direction1 = game::Direction::STAY;
    if (_receiver->isKeyDown(irr::KEY_UP))
        _direction1 = game::Direction::UP;
    if (_receiver->isKeyDown(irr::KEY_DOWN))
        _direction1 = game::Direction::DOWN;
    if (_receiver->isKeyDown(irr::KEY_LEFT))
        _direction1 = game::Direction::LEFT;
    if (_receiver->isKeyDown(irr::KEY_RIGHT))
        _direction1 = game::Direction::RIGHT;
    if (_receiver->isKeyDown(irr::KEY_KEY_M))
        _action1 = true;
    
    if (_playerNumber == 2) {
        _action2 = false;
        _direction2 = game::Direction::STAY;
        if (_receiver->isKeyDown(irr::KEY_KEY_Z))
            _direction2 = game::Direction::UP;
        if (_receiver->isKeyDown(irr::KEY_KEY_Q))
            _direction2 = game::Direction::LEFT;
        if (_receiver->isKeyDown(irr::KEY_KEY_S))
            _direction2 = game::Direction::DOWN;
        if (_receiver->isKeyDown(irr::KEY_KEY_D))
            _direction2 = game::Direction::RIGHT;
        if (_receiver->isKeyDown(irr::KEY_KEY_A))
            _action2 = true;
    }
    return 0;
}
