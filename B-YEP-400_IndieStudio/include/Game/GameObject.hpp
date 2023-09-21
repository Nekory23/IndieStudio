/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Bomberman include files.
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <boost/chrono.hpp>

namespace game{
    enum Type {
        GROUND,
        WALL,
        BRICK,
        BOMB,
        BONUS
    };

    enum BonusEffect {
        SPEED,
        BOMBUP,
        FIRE,
        WALLPASS,
        NOTHING
    };

    class GameObject {
        public:
            GameObject(Type type);
            virtual ~GameObject() = default;
            
            Type getType() const noexcept;
            bool getTraversable() const noexcept;
            bool getBreakable() const noexcept;

        protected:
            Type _type;
            bool _traversable;
            bool _breakable;
    };

    class Brick : public GameObject {
        public:
            Brick() : GameObject(BRICK) {
                int ran = std::rand() % 100;

                if (ran > 30)
                    _bonusType = NOTHING;
                else {
                    _bonusType = (BonusEffect)(rand() % 4);
                }
            }

            BonusEffect getBonusType() const noexcept;

        private:
            BonusEffect _bonusType;
    };

    class Bonus : public GameObject {
        public:
            Bonus(BonusEffect bonus = NOTHING) : GameObject(BONUS), _bonus(bonus) {}

            BonusEffect getBonus() const noexcept;
        
        private:
            BonusEffect _bonus;
    };

    class Bomb : public GameObject {
        public:
            Bomb(int idPlayer, int power=1) : GameObject(BOMB), _power(power), _idPlayer(idPlayer)
            {
                _timer = boost::chrono::process_real_cpu_clock::now() + boost::chrono::seconds{3};
                _test = boost::chrono::process_real_cpu_clock::now() + boost::chrono::milliseconds{2700};
            }

            int getPower(void) const noexcept;
            int getId(void) const noexcept;
            bool explose(void) noexcept;
            bool AnimExplose(void) noexcept;

        private:
            boost::chrono::process_real_cpu_clock::time_point _timer;
            boost::chrono::process_real_cpu_clock::time_point _test;
            int _power;
            int _idPlayer;
    };
}

#endif