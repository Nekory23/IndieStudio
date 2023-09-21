/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** EventReceiver
*/

#include "Graphic.hpp"

graph::EventReceiver::EventReceiver(irr::IrrlichtDevice *window, graph::Graphic &graph) noexcept : _window(window), _graph(graph), _keyIsDown()
{
    for (bool & i : _keyIsDown)
        i = false;
    for (auto i = 0; i != BUTTON_COUNT; ++i)
        _buttonClicked[i] = false;
}

bool graph::EventReceiver::isKeyDown(irr::EKEY_CODE keyCode) const noexcept
{
    return _keyIsDown[keyCode];
}

bool graph::EventReceiver::isButtonPressed(Buttons id) const noexcept
{
    return _buttonClicked[id];
}

bool graph::EventReceiver::keyInputs(const irr::SEvent &event) noexcept
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        _keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}

bool graph::EventReceiver::click(const irr::SEvent &event) noexcept
{
    if (event.EventType == irr::EET_GUI_EVENT && 
        event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
        _buttonClicked[event.GUIEvent.Caller->getID()] = true;
    return false;
}

bool graph::EventReceiver::OnEvent(const irr::SEvent &event)
{
    for (auto i = 0; i != BUTTON_COUNT; ++i)
        _buttonClicked[i] = false;
    if (click(event))
        return true;
    if (keyInputs(event))
        return true;
    return false;
}