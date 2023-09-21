/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** PlayerObject
*/

#include "Game.hpp"

void game::Bomberman::createPlayers(void) noexcept
{
    _players.push_back(new PlayerObject(50, 50));
    _players.push_back(new PlayerObject(50, 50 * 17));
    _players.push_back(new PlayerObject(50 * 35, 50 * 17));
    _players.push_back(new PlayerObject(50 * 35, 50));
}

void game::Bomberman::giveBonus(int id, BonusEffect bonus) noexcept
{
    if (bonus == SPEED)
        _players[id]->speedUp();
    if (bonus == BOMBUP)
        _players[id]->bombNbrUp();
    if (bonus == FIRE)
        _players[id]->powerUp();
    if (bonus == WALLPASS)
        _players[id]->wallPassUp();
}

void game::Bomberman::playerManagement(void) noexcept
{
    int posIUpRight = 0;
    int posIUpLeft = 0;
    int posYUpLeft = 0;
    int posYUpRight = 0;
    int posIDownRight = 0;
    int posIDownLeft = 0;
    int posYDownLeft = 0;
    int posYDownRight = 0;
    int posIMid = 0;
    int posYMid = 0;
    
    BonusEffect bonus;

    for (int i = 0; i < _playerNbr; i++) {
        if (_players[i]->isAlive() == true) {
            posIUpRight = _players[i]->getY() / 50;
            posIUpLeft = _players[i]->getY() / 50;
            posYUpRight = (_players[i]->getX() + 30) / 50;
            posYUpLeft = _players[i]->getX() / 50;
            posIDownRight = (_players[i]->getY() + 30) / 50;
            posIDownLeft = (_players[i]->getY() + 30) / 50;
            posYDownRight = (_players[i]->getX() + 30) / 50;
            posYDownLeft = _players[i]->getX() / 50;
            posIMid = (_players[i]->getY() + 15) / 50;
            posYMid = (_players[i]->getX() + 15) / 50;
            if (_matrice[posIUpLeft][posYUpLeft]->getType() == BONUS) {
                bonus = dynamic_cast<Bonus *>(_matrice[posIUpLeft][posYUpLeft])->getBonus();
                giveBonus(i, bonus);
                delete(_matrice[posIUpLeft][posYUpLeft]);
                _matrice[posIUpLeft][posYUpLeft] = new GameObject(GROUND);
            }
            if (_matrice[posIMid][posYMid]->getType() != BOMB) {
                if (_players[i]->getDirection() == Direction::LEFT
                && (_matrice[posIUpLeft][posYUpLeft]->getTraversable() == false
                || _matrice[posIDownLeft][posYDownLeft]->getTraversable() == false)) {
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIUpLeft][posYUpLeft]->getType() == BRICK ||
                    _matrice[posIDownLeft][posYDownLeft]->getType() == BRICK))
                        _players[i]->setDirection(Direction::LEFT);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
                if (_players[i]->getDirection() == Direction::RIGHT
                && (_matrice[posIUpRight][posYUpRight]->getTraversable() == false
                || _matrice[posIDownRight][posYDownRight]->getTraversable() == false)) {
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIUpRight][posYUpRight]->getType() == BRICK ||
                    _matrice[posIDownRight][posYDownRight]->getType() == BRICK))
                        _players[i]->setDirection(Direction::RIGHT);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
                if (_players[i]->getDirection() == Direction::UP
                && (_matrice[posIUpLeft][posYUpLeft]->getTraversable() == false
                || _matrice[posIUpRight][posYUpRight]->getTraversable() == false)) {
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIUpLeft][posYUpLeft]->getType() == BRICK ||
                    _matrice[posIUpRight][posYUpLeft]->getType() == BRICK))
                        _players[i]->setDirection(Direction::UP);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
                if (_players[i]->getDirection() == Direction::DOWN
                && (_matrice[posIDownLeft][posYDownLeft]->getTraversable() == false
                || _matrice[posIDownRight][posYDownRight]->getTraversable() == false)) {
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIDownLeft][posYDownLeft]->getType() == BRICK ||
                    _matrice[posIDownRight][posYDownRight]->getType() == BRICK))
                        _players[i]->setDirection(Direction::DOWN);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
            }
            _players[i]->move();
        }
    }
}

game::Direction game::Bomberman::betterWay(int i, int y) noexcept
{
    int right = 1;
    int left = 1;
    int up = 1;
    int down = 1;

    for (int x = i, u = y + 1; _matrice[x][u] && _matrice[x][u]->getTraversable() == true; u++, right++);
    for (int x = i, u = y - 1; _matrice[x][u] && _matrice[x][u]->getTraversable() == true; u--, left++);
    for (int x = i + 1, u = y; _matrice[x][u] && _matrice[x][u]->getTraversable() == true; x++, down++);
    for (int x = i - 1, u = y; _matrice[x][u] && _matrice[x][u]->getTraversable() == true; x--, up++);
    if (right > left && right > up && right > down)
        return RIGHT;
    if (left >= right && left >= up && left >= down)
        return LEFT;
    if (up >= left && up >= right && up >= down)
        return UP;
    if (down >= left && down >= up && down >= right)
        return DOWN;
    return STAY;
}

void game::Bomberman::AIManagement(void) noexcept
{
    int posIUpRight = 0;
    int posIUpLeft = 0;
    int posYUpLeft = 0;
    int posYUpRight = 0;
    int posIDownRight = 0;
    int posIDownLeft = 0;
    int posYDownLeft = 0;
    int posYDownRight = 0;
    int posIMid = 0;
    int posYMid = 0;
    int ran;
    BonusEffect bonus;

    for (int i = _playerNbr; i < 4; i++) {
        if (_players[i]->isAlive() == true) {
            posIUpRight = _players[i]->getY() / 50;
            posIUpLeft = _players[i]->getY() / 50;
            posYUpRight = (_players[i]->getX() + 30) / 50;
            posYUpLeft = _players[i]->getX() / 50;
            posIDownRight = (_players[i]->getY() + 30) / 50;
            posIDownLeft = (_players[i]->getY() + 30) / 50;
            posYDownRight = (_players[i]->getX() + 30) / 50;
            posYDownLeft = _players[i]->getX() / 50;
            posIMid = (_players[i]->getY() + 15) / 50;
            posYMid = (_players[i]->getX() + 15) / 50;
            if (_matrice[posIUpLeft][posYUpLeft]->getType() == BONUS) {
                bonus = dynamic_cast<Bonus *>(_matrice[posIUpLeft][posYUpLeft])->getBonus();
                giveBonus(i, bonus);
                delete(_matrice[posIUpLeft][posYUpLeft]);
                _matrice[posIUpLeft][posYUpLeft] = new GameObject(GROUND);
            }
            if (_players[i]->getDirection() == Direction::STAY)
                _players[i]->setDirection(betterWay(posIMid, posYMid));
            if (_matrice[posIMid][posYMid]->getType() != BOMB) {
                if (_players[i]->getDirection() == Direction::LEFT
                && (_matrice[posIUpLeft][posYUpLeft]->getTraversable() == false
                || _matrice[posIDownLeft][posYDownLeft]->getTraversable() == false)) {
                    if (_matrice[posIUpLeft][posYUpLeft]->getType() == BRICK
                    || _matrice[posIDownRight][posYDownRight]->getType() == BRICK) {
                        layBombPlayer(i);
                        _players[i]->setDirection(betterWay(posIMid, posYMid));
                    }
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIUpLeft][posYUpLeft]->getType() == BRICK ||
                    _matrice[posIDownLeft][posYDownLeft]->getType() == BRICK))
                        _players[i]->setDirection(Direction::RIGHT);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
                if (_players[i]->getDirection() == Direction::RIGHT
                && (_matrice[posIUpRight][posYUpRight]->getTraversable() == false
                || _matrice[posIDownRight][posYDownRight]->getTraversable() == false)) {
                    if (_matrice[posIUpRight][posYUpRight]->getType() == BRICK
                    || _matrice[posIDownRight][posYDownRight]->getType() == BRICK) {
                        layBombPlayer(i);
                        _players[i]->setDirection(betterWay(posIMid, posYMid));
                    }
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIUpRight][posYUpRight]->getType() == BRICK ||
                    _matrice[posIDownRight][posYDownRight]->getType() == BRICK))
                        _players[i]->setDirection(Direction::RIGHT);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
                if (_players[i]->getDirection() == Direction::UP
                && (_matrice[posIUpLeft][posYUpLeft]->getTraversable() == false
                || _matrice[posIUpRight][posYUpRight]->getTraversable() == false)) {
                    if (_matrice[posIUpLeft][posYUpLeft]->getType() == BRICK
                    || _matrice[posIUpRight][posYUpRight]->getType() == BRICK) {
                        layBombPlayer(i);
                        _players[i]->setDirection(betterWay(posIMid, posYMid));
                    }
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIUpLeft][posYUpLeft]->getType() == BRICK ||
                    _matrice[posIUpRight][posYUpLeft]->getType() == BRICK))
                        _players[i]->setDirection(Direction::UP);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
                if (_players[i]->getDirection() == Direction::DOWN
                && (_matrice[posIDownLeft][posYDownLeft]->getTraversable() == false
                || _matrice[posIDownRight][posYDownRight]->getTraversable() == false)) {
                    if (_matrice[posIDownLeft][posYDownLeft]->getType() == BRICK
                    || _matrice[posIDownRight][posYDownRight]->getType() == BRICK) {
                        layBombPlayer(i);
                        _players[i]->setDirection(betterWay(posIMid, posYMid));
                    }
                    if (_players[i]->getWallPass() == true &&
                    (_matrice[posIDownLeft][posYDownLeft]->getType() == BRICK ||
                    _matrice[posIDownRight][posYDownRight]->getType() == BRICK))
                        _players[i]->setDirection(Direction::DOWN);
                    else
                        _players[i]->setDirection(Direction::STAY);
                }
            }
            _players[i]->move();
        }
    }
}

void game::Bomberman::setDirectionPlayer(int id, Direction direction) noexcept
{
    _players[id]->setDirection(direction);
}

void game::Bomberman::layBombPlayer(int id) noexcept
{
    int posI = (_players[id]->getY() + 15) / 50;
    int posY = (_players[id]->getX() + 15) / 50;

    if (_players[id]->getStock() > 0 && _matrice[posI][posY]->getType() == GROUND) {
        delete(_matrice[posI][posY]);
        _matrice[posI][posY] = new Bomb(id, _players[id]->getPower());
        _players[id]->delBomb();
    }
}