/*
** EPITECH PROJECT, 2021
** B-YEP_indie
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Graphic.hpp"

namespace graph {

    enum menuState {
        MAIN,
        CHOICE,
        HOW_TO_PLAY
    };

    class Menu {
        public:
            Menu(irr::IrrlichtDevice *window) noexcept;
            ~Menu() = default;

            void createMainButtons(irr::IrrlichtDevice *window) noexcept;
            void disableMainButtons() noexcept;
            void enableMainButtons() noexcept;

            void createChoiceButtons(irr::IrrlichtDevice *window) noexcept;
            void disableChoiceButtons() noexcept;
            void enableChoiceButtons() noexcept;

            void displaySoundButtons(bool state) noexcept;
            void disableSoundButtons() noexcept;

            void setState(menuState state) noexcept;
            graph::menuState getState() const noexcept;

            void draw(irr::IrrlichtDevice *window) noexcept;
        private:
            std::map<std::string, irr::video::ITexture *> _textures;
            std::map<std::string, irr::gui::IGUIButton *> _buttons;
            menuState _state;
    };
}

#endif /* !MENU_HPP_ */
