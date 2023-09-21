/*
** EPITECH PROJECT, 2021
** B-YEP_indie
** File description:
** DispGame
*/

#ifndef DISPGAME_HPP_
#define DISPGAME_HPP_

#include "Graphic.hpp"

namespace graph {
    class EventReceiver;
    class Player;

    class Game {
        public:
            explicit Game(std::vector<std::vector<game::GameObject *>> map, std::vector<game::PlayerObject *> players, irr::IrrlichtDevice *window, int nbr) noexcept;
            ~Game();

            void loadTextures(irr::IrrlichtDevice *window) noexcept;
            void setScene(irr::IrrlichtDevice *window) noexcept;

            void setNewPlayerPositions(int id, std::vector<game::PlayerObject *> players, game::Direction direction, int nbr) noexcept;

            std::vector<std::vector<irr::scene::ISceneNode *>> getCubes() const noexcept;
            std::vector<std::vector<irr::scene::ISceneNode *>> getFloor() const noexcept;
            std::vector<Player *> getPlayers() const noexcept;

            void createPlayers(std::vector<game::PlayerObject *> players, irr::IrrlichtDevice *window, int nbr) noexcept;
            void createBlock(std::vector<std::vector<game::GameObject *>> map, irr::IrrlichtDevice *window) noexcept;
            void createPauseButtons(irr::IrrlichtDevice *window) noexcept;

            void updateMap(std::vector<std::vector<game::GameObject *>> map, irr::IrrlichtDevice *window) noexcept;
            void updatePlayers(std::vector<game::PlayerObject *> players) noexcept;

            void enablePauseButtons() noexcept;
            void disablePauseButtons() noexcept;
            void enableDraw() noexcept;
            void disableDraw() noexcept;

            void draw(irr::IrrlichtDevice *window, std::vector<game::PlayerObject *> players, std::vector<std::vector<game::GameObject *>> map) noexcept;
            void pause(irr::IrrlichtDevice *window) noexcept;

        private:
            std::map<std::string, irr::video::ITexture *> _textures;
            std::vector<std::vector<irr::scene::ISceneNode *>> _cubes;
            std::vector<std::vector<irr::scene::ISceneNode *>> _floor;
            std::map<std::string, irr::gui::IGUIButton *> _buttons;
            std::vector<Player *> _players;
    };

    class Player {
        public:
            explicit Player(irr::IrrlichtDevice *_window, int rotation, int posx, int posy, std::string name) noexcept;
            ~Player() = default;

            irr::scene::IAnimatedMeshSceneNode *getNode() const noexcept;
            std::string getName() const noexcept;

        private:
            irr::scene::IAnimatedMesh *_playerMesh;
            irr::scene::IAnimatedMeshSceneNode * _playerNode;
            irr::f32 _frameDeltaTime;
            std::string _playerName;
    };
}

#endif /* !DISPGAME_HPP_ */
