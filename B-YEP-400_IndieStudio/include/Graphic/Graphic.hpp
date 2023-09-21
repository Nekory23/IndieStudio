/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include <map>
#include <irrlicht.h>
#include <SFML/Audio.hpp>
#include "../EnumGraph.hpp"
#include "GameObject.hpp"
#include "PlayerObject.hpp"

namespace graph {
    class EventReceiver;
    class Menu;
    class Game;
    class Player;

    enum Buttons {
        // menu
        NEW_BUTTON_ID,
        LOAD_BUTTON_ID,
        QUIT_BUTTON_ID,
        SOUND_ON_BUTTON_ID,
        SOUND_OFF_BUTTON_ID,
        // choice
        ONE_BUTTON_ID,
        TWO_BUTTON_ID,
        BACK_BUTTON_ID,
        HTP_BUTTON_ID,
        // pause
        RESUME_BUTTON_ID,
        SAVE_AND_QUIT_BUTTON_ID,
        QUIT_GAME_BUTTON_ID,
        // count
        BUTTON_COUNT
    };

    class Graphic {
        public:
            Graphic() noexcept;
            ~Graphic();

            void createGameOverScreens() noexcept;

            int display(std::vector<std::vector<game::GameObject *>> map, std::vector<game::PlayerObject *> players) noexcept;
            int manageMenuButtons() noexcept;
            int managePauseButtons() noexcept;
            int manageControls() noexcept;

            void setNewPlayerPositions(int id, std::vector<game::PlayerObject *> players, game::Direction direction) noexcept;
            void setPlayerNumber(int nbr) noexcept;

            bool getIsOpen() const noexcept;
            graph::Game *getGame() const noexcept;
            graph::Menu *getMenu() const noexcept;
            int getPlayerNumber() const noexcept;
            game::Direction getDirectionPlayerOne() const noexcept;
            game::Direction getDirectionPlayerTwo() const noexcept;
            bool getActionPlayerOne() const noexcept;
            bool getActionPlayerTwo() const noexcept;
            graph::stateGraph getState() const noexcept;
            bool getSave() const noexcept;
            bool getLoad() const noexcept;

            void setLoad(bool load) noexcept;
            void setSave(bool save) noexcept;
            void setState(graph::stateGraph state) noexcept;

        private:
            void displayMenu() noexcept;
            void displayPause() noexcept;
            void displayStart() noexcept;
            void displayGame(std::vector<std::vector<game::GameObject *>> map, std::vector<game::PlayerObject *> players) noexcept;
            int displayOver() noexcept;

            graph::EventReceiver  *_receiver;
            graph::Menu *_menu;
            graph::Game *_game;

            irr::IrrlichtDevice *_window;
            irr::video::ITexture *_texture;
            sf::Music *_music;
            graph::stateGraph _state;

            std::map<std::string, irr::video::ITexture *> _gameOver;

            int _playerNumber;
            game::Direction _direction1;
            game::Direction _direction2;
            bool _save;
            bool _saveFile;
            bool _load;
            bool _action1;
            bool _action2;

            bool _musicState;
    };

    class EventReceiver : public irr::IEventReceiver {
        public:
            EventReceiver(irr::IrrlichtDevice *window, graph::Graphic &graph) noexcept;

            bool OnEvent(const irr::SEvent &event) override;
            bool click(const irr::SEvent &event) noexcept;
            bool keyInputs(const irr::SEvent &event) noexcept;

            virtual bool isKeyDown(irr::EKEY_CODE keyCode) const noexcept;
            virtual bool isButtonPressed(Buttons) const noexcept;

        private:
            irr::IrrlichtDevice *_window;
            graph::Graphic &_graph;

            bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
            bool _buttonClicked[BUTTON_COUNT];
    };
}

#endif /* !GRAPHIC_HPP_ */
