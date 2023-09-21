/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** map functions.
*/

#include "Game.hpp"

static char changeBlock(int i, int y)
{
    int ran = std::rand() % 100;

    if (ran <= 65)
        return 'X';
    else
        return ' ';
}

static std::vector<std::string> setWalls(int size_l,
int size_L, std::vector<std::string> map)
{
    for (int i = 1; i < size_l - 1; i++) {
        for (int y = 1; y < size_L - 1; y++) {
            if (map[i][y] == ' ')
                map[i][y] = changeBlock(i, y);
        }
    }
    map[1][1] = ' ';
    map[1][2] = ' ';
    map[2][1] = ' ';
    map[1][size_L - 2] = ' ';
    map[1][size_L - 3] = ' ';
    map[2][size_L - 2] = ' ';
    map[size_l - 2][1] = ' ';
    map[size_l - 2][2] = ' ';
    map[size_l - 3][1] = ' ';
    map[size_l - 2][size_L - 2] = ' ';
    map[size_l - 2][size_L - 3] = ' ';
    map[size_l - 3][size_L - 2] = ' ';
    return map;
}

void game::Bomberman::createMap(void) noexcept
{
    _map =
    {"*************************************", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "* * * * * * * * * * * * * * * * * * *", \
    "*                                   *", \
    "*************************************"};
    _size_L = _map[0].length();
    _size_l = _map.size();
    _map = setWalls(_size_l, _size_L, _map);
}

std::vector<std::vector<game::GameObject *>> game::Bomberman::getMap(void) const noexcept
{
    return _matrice;
}