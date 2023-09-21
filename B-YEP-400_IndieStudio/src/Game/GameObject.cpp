/*
** EPITECH PROJECT, 2o2*
** Indie studio
** File description:
** GameObject class file.
*/

#include "GameObject.hpp"

game::GameObject::GameObject(game::Type type)
{
    _type = type;
    if (_type == game::BRICK) {
        _traversable = false;
        _breakable = true;
    }
    if (_type == game::WALL) {
        _traversable = false;
        _breakable = false;
    }
    if (_type == game::GROUND) {
        _traversable = true;
        _breakable = false;
    }
    if (_type == game::BOMB) {
        _traversable = false;
        _breakable = true;
    }
    if (_type == game::BONUS) {
        _traversable = true;
        _breakable = true;
    }
}

game::Type game::GameObject::getType() const noexcept
{
    return _type;
}

bool game::GameObject::getTraversable() const noexcept
{
    return _traversable;
}

bool game::GameObject::getBreakable() const noexcept
{
    return _breakable;
}

int game::Bomb::getPower() const noexcept
{
    return _power;
}

game::BonusEffect game::Brick::getBonusType() const noexcept
{
    return _bonusType;
}

game::BonusEffect game::Bonus::getBonus() const noexcept
{
    return _bonus;
}

bool game::Bomb::explose(void) noexcept
{
    if (boost::chrono::process_real_cpu_clock::now() > _timer)
        return true;
    else
        return false;
}

bool game::Bomb::AnimExplose(void) noexcept
{
    if (boost::chrono::process_real_cpu_clock::now() > _test)
        return true;
    else
        return false;
}

int game::Bomb::getId(void) const noexcept
{
    return _idPlayer;
}