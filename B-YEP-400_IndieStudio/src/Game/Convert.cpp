/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** convert and save functions.
*/

#include "Game.hpp"

void game::Bomberman::convertToObject(void) noexcept
{
    int power;
    std::string str;

    _matrice.resize(_size_l);
    for (int i = 0; i < _size_l; i++) {
        _matrice[i].clear();
        for (int y = 0; y < _size_L; y++) {
            if (_map[i][y] == '*')
                _matrice[i].push_back(new GameObject(WALL));
            if (_map[i][y] == ' ')
                _matrice[i].push_back(new GameObject(GROUND));
            if (_map[i][y] == 'X')
                _matrice[i].push_back(new Brick);
            if (_map[i][y] >= '0' && _map[i][y] <= '9') {
                str.clear();
                str.push_back(_map[i][y]);
                power = dynamic_cast<PlayerObject *>(_players[std::stoi(str)])->getPower();
                _matrice[i].push_back(new Bomb(std::stoi(str), power));
            }
            if (_map[i][y] == 'S')
                _matrice[i].push_back(new Bonus(SPEED));
            if (_map[i][y] == 'B')
                _matrice[i].push_back(new Bonus(BOMBUP));
            if (_map[i][y] == 'W')
                _matrice[i].push_back(new Bonus(WALLPASS));
            if (_map[i][y] == 'F')
                _matrice[i].push_back(new Bonus(FIRE));
        }
    }
}

std::string game::Bomberman::convertToString(void) noexcept
{
    BonusEffect bonusType;
    std::string str;
    int bombId;

    for (int i = 0; i < _size_l; i++) {
        for (int y = 0; y < _size_L; y++) {
            if (_matrice[i][y]->getType() == WALL)
                str.push_back('*');
            if (_matrice[i][y]->getType() == GROUND)
                str.push_back(' ');
            if (_matrice[i][y]->getType() == BRICK)
                str.push_back('X');
            if (_matrice[i][y]->getType() == BONUS) {
                bonusType  = dynamic_cast<Bonus *>(_matrice[i][y])->getBonus();
                if (bonusType == BOMBUP)
                    str.push_back('B');
                if (bonusType == WALLPASS)
                    str.push_back('W');
                if (bonusType == SPEED)
                    str.push_back('S');
                if (bonusType == FIRE)
                    str.push_back('F');
            } 
            if (_matrice[i][y]->getType() == BOMB) {
                bombId = dynamic_cast<Bomb *>(_matrice[i][y])->getId();
                str.push_back(bombId + '0');
            }
        }
        str.push_back('\n');
    }
    return str;
}