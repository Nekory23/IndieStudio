/*
** EPITECH PROJECT, 2o2*
** Indie studio
** File description:
** Bomberman game.
*/

#include "Game.hpp"

game::Bomberman::Bomberman(int players, bool load) : _playerNbr(players), _load(load)
{
    std::srand(std::time(nullptr));
    if (load == false) {
        createMap();
        createPlayers();
    } else {
        loadPlayers();
        loadMap();
    }
    convertToObject();
}

game::Bomberman::~Bomberman()
{
    _map.clear();
}

int game::Bomberman::reset(void) noexcept
{
    int ret1 = 0;
    int ret2 = 0;

    std::srand(std::time(nullptr));
    _map.clear();
    _players.clear();
    if (_load == false) {
        createMap();
        createPlayers();
    } else {
        ret1 = loadPlayers();
        ret2 = loadMap();
        if (ret1 == 84 || ret2 == 84)
            return 84;
    }
    convertToObject();
    return 0;
}

std::vector<game::PlayerObject *> game::Bomberman::getPlayers(void) const noexcept {
    return _players;
}

void game::Bomberman::setLoad(bool load) noexcept
{
    _load = load;
}

void game::Bomberman::setPlayerNbr(int nb) noexcept
{
    _playerNbr = nb;
}

bool game::Bomberman::gameover(void) noexcept
{
    int playersLeft = 0;

    for (int i = 0; i < 4; i++) {
        if (_players[i]->isAlive() == true)
            playersLeft++;
    }
    if (playersLeft <= 1)
        return true;
    return false;
}

int game::Bomberman::getPlayerNbr() noexcept
{
    return _playerNbr;
}