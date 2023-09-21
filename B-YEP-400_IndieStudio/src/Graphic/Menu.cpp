/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Menu
*/

#include "Graphic.hpp"
#include "Menu.hpp"

graph::Menu::Menu(irr::IrrlichtDevice *window) noexcept
{
    _state = MAIN;
    _textures.emplace((std::string) "Background", window->getVideoDriver()->getTexture("assets/ground/background.png"));
    _textures.emplace((std::string) "how to play", window->getVideoDriver()->getTexture("assets/ground/howToPlay.png"));

    createMainButtons(window);
    createChoiceButtons(window);
}

void graph::Menu::setState(menuState state) noexcept
{
    _state = state;
}

graph::menuState graph::Menu::getState() const noexcept
{
    return _state;
}

void graph::Menu::createMainButtons(irr::IrrlichtDevice *window) noexcept
{
    _textures.emplace((std::string) "new button", window->getVideoDriver()->getTexture("assets/buttons/new_button.png"));
    _textures.emplace((std::string) "load button", window->getVideoDriver()->getTexture("assets/buttons/load_button.png"));
    _textures.emplace((std::string) "quit button", window->getVideoDriver()->getTexture("assets/buttons/quit_button.png"));
    _textures.emplace((std::string) "sound on button", window->getVideoDriver()->getTexture("assets/buttons/sound_on.png"));
    _textures.emplace((std::string) "sound off button", window->getVideoDriver()->getTexture("assets/buttons/sound_off.png"));

    _buttons.emplace((std::string) "new", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, NEW_BUTTON_ID, L""));
    _buttons.emplace((std::string) "load", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, LOAD_BUTTON_ID, L""));
    _buttons.emplace((std::string) "quit", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, QUIT_BUTTON_ID, L""));
    _buttons.emplace((std::string) "sound on", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 87, 69), nullptr, SOUND_ON_BUTTON_ID, L""));
    _buttons.emplace((std::string) "sound off", window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 87, 69), nullptr, SOUND_OFF_BUTTON_ID, L""));

    _buttons["new"]->setRelativePosition(irr::core::position2d<irr::s32>(190, 500));
    _buttons["load"]->setRelativePosition(irr::core::position2d<irr::s32>(1380, 500));
    _buttons["quit"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 850));
    _buttons["sound on"]->setRelativePosition(irr::core::position2d<irr::s32>(1580, 850));
    _buttons["sound off"]->setRelativePosition(irr::core::position2d<irr::s32>(1580, 850));

    _buttons["new"]->setImage(_textures["new button"]);
    _buttons["load"]->setImage(_textures["load button"]);
    _buttons["quit"]->setImage(_textures["quit button"]);
    _buttons["sound on"]->setImage(_textures["sound on button"]);
    _buttons["sound off"]->setImage(_textures["sound off button"]);

    _buttons["sound off"]->setVisible(false);
    _buttons["sound off"]->setEnabled(false);
}

void graph::Menu::createChoiceButtons(irr::IrrlichtDevice *window) noexcept
{
    _textures.emplace(std::string ("one button"), window->getVideoDriver()->getTexture("assets/buttons/one_button.png"));
    _textures.emplace(std::string ("two button"), window->getVideoDriver()->getTexture("assets/buttons/two_button.png"));
    _textures.emplace(std::string ("back button"), window->getVideoDriver()->getTexture("assets/buttons/back_button.png"));
    _textures.emplace(std::string ("how to play button"), window->getVideoDriver()->getTexture("assets/buttons/how_to_play_button.png"));

    _buttons.emplace(std::string ("one"), window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, ONE_BUTTON_ID, L""));
    _buttons.emplace(std::string ("two"), window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, TWO_BUTTON_ID, L""));
    _buttons.emplace(std::string ("back"), window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, BACK_BUTTON_ID, L""));
    _buttons.emplace(std::string ("htp"), window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 353, 69), nullptr, HTP_BUTTON_ID, L""));

    _buttons["one"]->setRelativePosition(irr::core::position2d<irr::s32>(190, 500));
    _buttons["two"]->setRelativePosition(irr::core::position2d<irr::s32>(1380, 500));
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 850));
    _buttons["htp"]->setRelativePosition(irr::core::position2d<irr::s32>(1380, 950));

    _buttons["one"]->setImage(_textures["one button"]);
    _buttons["two"]->setImage(_textures["two button"]);
    _buttons["back"]->setImage(_textures["back button"]);
    _buttons["htp"]->setImage(_textures["how to play button"]);

    disableChoiceButtons();
}

void graph::Menu::disableMainButtons() noexcept
{
    if (_buttons["new"]->isEnabled())
        _buttons["new"]->setEnabled(false);
    if (_buttons["new"]->isVisible())
        _buttons["new"]->setVisible(false);
    if (_buttons["load"]->isEnabled())
        _buttons["load"]->setEnabled(false);
    if (_buttons["load"]->isVisible())
        _buttons["load"]->setVisible(false);
    if (_buttons["quit"]->isEnabled())
        _buttons["quit"]->setEnabled(false);
    if (_buttons["quit"]->isVisible())
        _buttons["quit"]->setVisible(false);
}

void graph::Menu::enableMainButtons() noexcept
{
    if (!_buttons["new"]->isEnabled())
        _buttons["new"]->setEnabled(true);
    if (!_buttons["new"]->isVisible())
        _buttons["new"]->setVisible(true);
    if (!_buttons["load"]->isEnabled())
        _buttons["load"]->setEnabled(true);
    if (!_buttons["load"]->isVisible())
        _buttons["load"]->setVisible(true);
    if (!_buttons["quit"]->isEnabled())
        _buttons["quit"]->setEnabled(true);
    if (!_buttons["quit"]->isVisible())
        _buttons["quit"]->setVisible(true);
}

void graph::Menu::disableChoiceButtons() noexcept
{
    if (_buttons["one"]->isEnabled())
        _buttons["one"]->setEnabled(false);
    if (_buttons["one"]->isVisible())
        _buttons["one"]->setVisible(false);
    if (_buttons["two"]->isEnabled())
        _buttons["two"]->setEnabled(false);
    if (_buttons["two"]->isVisible())
        _buttons["two"]->setVisible(false);
    if (_buttons["back"]->isEnabled())
        _buttons["back"]->setEnabled(false);
    if (_buttons["back"]->isVisible())
        _buttons["back"]->setVisible(false);
    if (_buttons["htp"]->isEnabled())
        _buttons["htp"]->setEnabled(false);
    if (_buttons["htp"]->isVisible())
        _buttons["htp"]->setVisible(false);
}

void graph::Menu::enableChoiceButtons() noexcept
{
    if (!_buttons["one"]->isEnabled())
        _buttons["one"]->setEnabled(true);
    if (!_buttons["one"]->isVisible())
        _buttons["one"]->setVisible(true);
    if (!_buttons["two"]->isEnabled())
        _buttons["two"]->setEnabled(true);
    if (!_buttons["two"]->isVisible())
        _buttons["two"]->setVisible(true);
    if (!_buttons["back"]->isEnabled())
        _buttons["back"]->setEnabled(true);
    if (!_buttons["back"]->isVisible())
        _buttons["back"]->setVisible(true);
    if (!_buttons["htp"]->isEnabled())
        _buttons["htp"]->setEnabled(true);
    if (!_buttons["htp"]->isVisible())
        _buttons["htp"]->setVisible(true);
}

void graph::Menu::displaySoundButtons(bool state) noexcept
{
    if (state) {
        _buttons["sound off"]->setVisible(false);
        _buttons["sound off"]->setEnabled(false);
        _buttons["sound on"]->setVisible(true);
        _buttons["sound on"]->setEnabled(true);
    }
    else {
        _buttons["sound off"]->setVisible(true);
        _buttons["sound off"]->setEnabled(true);
        _buttons["sound on"]->setVisible(false);
        _buttons["sound on"]->setEnabled(false);
    }
}

void graph::Menu::disableSoundButtons() noexcept
{
    _buttons["sound on"]->setVisible(false);
    _buttons["sound on"]->setEnabled(false);
    _buttons["sound off"]->setVisible(false);
    _buttons["sound off"]->setEnabled(false);
}

void graph::Menu::draw(irr::IrrlichtDevice *window) noexcept
{
    switch (_state) {
        case MAIN :
            enableMainButtons();
            disableChoiceButtons();    
            break;
        case CHOICE :
            enableChoiceButtons();
            disableMainButtons();
            break;
        case HOW_TO_PLAY :
            disableChoiceButtons();
            disableMainButtons();
            disableSoundButtons();
            window->getVideoDriver()->draw2DImage(_textures["how to play"], irr::core::position2d<irr::s32>(0, 0),
                irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
            return;
    }
    window->getVideoDriver()->draw2DImage(_textures["Background"], irr::core::position2d<irr::s32>(0, 0),
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}