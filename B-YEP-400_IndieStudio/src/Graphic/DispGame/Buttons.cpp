/*
** EPITECH PROJECT, 2021
** B-YEP_IndieStudio
** File description:
** Buttons
*/

#include "DispGame.hpp"

void graph::Game::createPauseButtons(irr::IrrlichtDevice *window) noexcept
{
    _buttons.emplace((std::string) "resume", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, RESUME_BUTTON_ID, L""));
    _buttons.emplace((std::string) "quit_game", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, QUIT_GAME_BUTTON_ID, L""));
    _buttons.emplace((std::string) "save", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, SAVE_AND_QUIT_BUTTON_ID, L""));

    _buttons["resume"]->setImage(_textures["resume button"]);
    _buttons["quit_game"]->setImage(_textures["quit_game button"]);
    _buttons["save"]->setImage(_textures["save button"]);

    _buttons["resume"]->setRelativePosition(irr::core::position2d<irr::s32>(190, 500));
    _buttons["quit_game"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 850));
    _buttons["save"]->setRelativePosition(irr::core::position2d<irr::s32>(1380, 500));

    disablePauseButtons();
}

void graph::Game::enablePauseButtons() noexcept
{
    if (!_buttons["resume"]->isEnabled())
        _buttons["resume"]->setEnabled(true);
    if (!_buttons["resume"]->isVisible())
        _buttons["resume"]->setVisible(true);
    if (!_buttons["quit_game"]->isEnabled())
        _buttons["quit_game"]->setEnabled(true);
    if (!_buttons["quit_game"]->isVisible())
        _buttons["quit_game"]->setVisible(true);
    if (!_buttons["save"]->isEnabled())
        _buttons["save"]->setEnabled(true);
    if (!_buttons["save"]->isVisible())
        _buttons["save"]->setVisible(true);
}

void graph::Game::disablePauseButtons() noexcept
{
    if (_buttons["resume"]->isEnabled())
        _buttons["resume"]->setEnabled(false);
    if (_buttons["resume"]->isVisible())
        _buttons["resume"]->setVisible(false);
    if (_buttons["quit_game"]->isEnabled())
        _buttons["quit_game"]->setEnabled(false);
    if (_buttons["quit_game"]->isVisible())
        _buttons["quit_game"]->setVisible(false);
    if (_buttons["save"]->isEnabled())
        _buttons["save"]->setEnabled(false);
    if (_buttons["save"]->isVisible())
        _buttons["save"]->setVisible(false);
}
