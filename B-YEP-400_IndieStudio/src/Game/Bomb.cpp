/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Bombe functions.
*/

#include "Game.hpp"

void game::Bomberman::checkIsPlayerDead(int i, int y) noexcept
{
    int posIUp;
    int posYLeft;

    for (int x = 0; x < _players.size(); x++) {
        posIUp = (_players[x]->getY() + 15) / 50;
        posYLeft = (_players[x]->getX() + 15) / 50;
        if (posIUp == i && posYLeft == y)
            this->_players[x]->die();
    }
}

int game::Bomberman::doExplosion(int i, int y) noexcept
{
    int stop = 0;
    game::BonusEffect bonus;

    checkIsPlayerDead(i, y);
    if (_matrice[i][y]->getBreakable() == true) {
        if (_matrice[i][y]->getType() == game::BOMB) {
            trigger(i, y);
            return 1;
        }
        if (_matrice[i][y]->getType() == game::BONUS) {
            delete(_matrice[i][y]);
            _matrice[i][y] = new game::GameObject(game::GROUND);
            return 0;
        }
        if (_matrice[i][y]->getType() == game::BRICK) {
            bonus = dynamic_cast<game::Brick *>(_matrice[i][y])->getBonusType();
            delete(_matrice[i][y]);
            if (bonus != game::NOTHING) {
                _matrice[i][y] = new game::Bonus(bonus);
                stop = 1;
            } else
                _matrice[i][y] = new game::GameObject(game::GROUND);
        }
        if (_matrice[i][y]->getType() != game::BONUS || stop == 1)
            return 1;
    }
    return 0;
}

void game::Bomberman::trigger(int i, int y) noexcept
{
    int power = dynamic_cast<game::Bomb *>(_matrice[i][y])->getPower();

    delete(_matrice[i][y]);
    _matrice[i][y] = new game::GameObject(game::GROUND);
    checkIsPlayerDead(i, y);
    for (int w = power, z = i - 1; w > 0
    && _matrice[z][y]->getType() != game::WALL; w--, z--) {
        if (doExplosion(z, y) == 1)
            break;
    }
    for (int w = power, z = i + 1; w > 0
    && _matrice[z][y]->getType() != game::WALL; w--, z++) {
        if (doExplosion(z, y) == 1)
            break;
    }
    for (int w = power, z = y - 1; w > 0
    && _matrice[i][z]->getType() != game::WALL; w--, z--) {
        if (doExplosion(i, z) == 1)
            break;
    }
    for (int w = power, z = y + 1; w > 0
    && _matrice[i][z]->getType() != game::WALL; w--, z++) {
        if (doExplosion(i, z) == 1)
            break;
    }
}

void game::Bomberman::explosion(void) noexcept
{
    int id;
    bool timer;

    for (int i = 0; i < _size_l; i++) {
        for (int y = 0; y < _size_L; y++) {
            if (_matrice[i][y]->getType() == game::BOMB) {
                timer = dynamic_cast<game::Bomb *>(_matrice[i][y])->explose();
                id = dynamic_cast<game::Bomb *>(_matrice[i][y])->getId();
                if (timer == true) {
                    _players[id]->addBomb();
                    trigger(i, y);
                }
            }
        }
    }   
}