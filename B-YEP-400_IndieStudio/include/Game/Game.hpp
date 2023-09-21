/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Bomberman include files.
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <string>
#include <vector>
#include "GameObject.hpp"
#include "PlayerObject.hpp"

namespace game {
    class Bomberman {
        public:
            Bomberman(int players = 1, bool load = false);
            ~Bomberman();

            void createMap(void) noexcept;
            void createPlayers(void) noexcept;

            int reset(void) noexcept;

            void convertToObject(void) noexcept;
            std::string convertToString(void) noexcept;

            void playerManagement() noexcept;
            void AIManagement() noexcept;
            Direction betterWay(int i, int y) noexcept;
            void giveBonus(int id, BonusEffect bonus) noexcept;
            void checkIsPlayerDead(int i, int y) noexcept;

            int doExplosion(int i, int y) noexcept;
            void trigger(int i, int y) noexcept;
            void explosion(void) noexcept;
            void layBombPlayer(int id) noexcept;

            void save(void) noexcept;
            int loadMap(void) noexcept;
            int loadPlayers(void) noexcept;

            std::vector<game::PlayerObject *> getPlayers(void) const noexcept;
            std::vector<std::vector<game::GameObject *>> getMap(void) const noexcept;
            bool gameover(void) noexcept;
            int getPlayerNbr(void) noexcept;

            void setLoad(bool load) noexcept;
            void setPlayerNbr(int nb) noexcept;
            void setDirectionPlayer(int id, Direction direction) noexcept;

        private:
            std::vector<std::string> _map;
            std::vector<std::vector<game::GameObject *>> _matrice;
            int _size_L;
            int _size_l;

            std::vector<game::PlayerObject *> _players;
            int _playerNbr;

            bool _load;
    };
}

#endif