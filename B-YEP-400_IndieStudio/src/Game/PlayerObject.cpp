/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** PlayerObject
*/

#include "PlayerObject.hpp"

float game::PlayerObject::getX(void) const noexcept
{
    return _x;
}

float game::PlayerObject::getY(void) const noexcept
{
    return _y;
}

void game::PlayerObject::setDirection(Direction direction) noexcept
{
    _direction = direction;
}

game::Direction game::PlayerObject::getDirection(void) const noexcept
{
    return _direction;
}

void game::PlayerObject::move(void) noexcept
{
    if (_direction == UP)
        _y -= _speed;
    if (_direction == DOWN)
        _y += _speed;
    if (_direction == LEFT)
        _x -= _speed;
    if (_direction == RIGHT)
        _x += _speed;
}

int game::PlayerObject::getPower(void) const noexcept
{
    return _power;
}

int game::PlayerObject::getBombNbr(void) const noexcept
{
    return _bombNbr;
}

void game::PlayerObject::bombNbrUp(void) noexcept
{
    _bombNbr++;
    _stock++;
}

void game::PlayerObject::speedUp(void) noexcept
{
    _speed += 1;
}

void game::PlayerObject::addBomb(void) noexcept
{
    _stock++;
}

void game::PlayerObject::delBomb(void) noexcept
{
    _stock--;
}

void game::PlayerObject::powerUp(void) noexcept
{
    _power++;
}

bool game::PlayerObject::getWallPass(void) const noexcept
{
    return _wallPass;
}

int game::PlayerObject::getStock(void) const noexcept
{
    return _stock;
}

int game::PlayerObject::getSpeed(void) const noexcept
{
    return _speed;
}

void game::PlayerObject::die(void) noexcept
{
    _alive = false;
}

bool game::PlayerObject::isAlive(void) const noexcept
{
    return _alive;
}

void game::PlayerObject::wallPassUp(void) noexcept
{
    _wallPass = true;
}

void game::PlayerObject::setAlive(bool alive) noexcept
{
    _alive = alive;
}

void game::PlayerObject::setBombNbr(int bombNbr) noexcept
{
    _bombNbr = bombNbr;
}

void game::PlayerObject::setSpeed(double speed) noexcept
{
    _speed = speed;
}

void game::PlayerObject::setPower(int power) noexcept
{
    _power = power;
}

void game::PlayerObject::setWallPass(bool wallPass) noexcept
{
    _wallPass = wallPass;
}

void game::PlayerObject::setX(float X) noexcept
{
    _x = X;
}

void game::PlayerObject::setY(float Y) noexcept
{
    _y = Y;
}

void game::PlayerObject::setStock(int stock) noexcept
{
    _stock = stock;
}