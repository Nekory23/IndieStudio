/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Bomberman include files.
*/

#ifndef PLAYEROBJECT_HPP_
#define PLAYEROBJECT_HPP_

namespace game {
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STAY
    };

    class PlayerObject {
        public:
            PlayerObject(float x, float y) : _x(x), _y(y),
                _bombNbr(1), _speed(2), _power(1), _stock(1), _wallPass(false), _alive(true), _direction(game::STAY) {}
            ~PlayerObject();

            void move(void) noexcept;
            void die(void) noexcept;

            void bombNbrUp(void) noexcept;
            void speedUp(void) noexcept;
            void addBomb(void) noexcept;
            void delBomb(void) noexcept;
            void powerUp(void) noexcept;
            void wallPassUp(void) noexcept;

            Direction getDirection(void) const noexcept;
            int getBombNbr(void) const noexcept;
            int getPower(void) const noexcept;
            int getSpeed(void) const noexcept;
            bool getWallPass(void) const noexcept;
            int getStock(void) const noexcept;
            float getX(void) const noexcept;
            float getY(void) const noexcept;

            bool isAlive(void) const noexcept;

            void setDirection(Direction direction) noexcept;
            void setAlive(bool alive) noexcept;
            void setBombNbr(int bombNbr) noexcept;
            void setSpeed(double speed) noexcept;
            void setSpeed(void) noexcept;
            void setPower(int power) noexcept;
            void setWallPass(bool wallPass) noexcept;
            void setX(float X) noexcept;
            void setY(float Y) noexcept;
            void setStock(int stock) noexcept;
        
        private:
            bool _alive;
            float _x;
            float _y;
            int _stock;
            Direction _direction;

            int _bombNbr;
            double _speed;
            int _power;
            bool _wallPass;
    };

    class AI : public PlayerObject {
    };
}

#endif