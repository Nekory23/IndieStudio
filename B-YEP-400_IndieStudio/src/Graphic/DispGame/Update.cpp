/*
** EPITECH PROJECT, 2021
** B-YEP_IndieStudio
** File description:
** Update
*/

#include "DispGame.hpp"

static float convertToX(float posx)
{
    return (posx * 2.0f) / 50.0f;
}

static float convertToY(float posy)
{
    return ((posy * 2.0f) / 50.0f) * -1.0f;
}

void graph::Game::setNewPlayerPositions(int id, std::vector<game::PlayerObject *> players, game::Direction direction, int playerNbr) noexcept
{
    float x = convertToX(players[id]->getX());
    float y = convertToY(players[id]->getY());

    if (_players[id] == nullptr)
        return;
    
    _players[id]->getNode()->setPosition(irr::core::vector3df(x, y, 0));

    if (direction == game::Direction::STAY) {
        if (_players[id]->getNode()->getFrameNr() >= 200 && _players[id]->getNode()->getFrameNr() <= 280)
            return;
        else
            _players[id]->getNode()->setFrameLoop(200, 280);
    }

    if (id == 0 && direction != game::Direction::STAY)
        switch (direction) {
        case game::Direction::RIGHT :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 90)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 90));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::LEFT :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, -90)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, -90));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::UP :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 180)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 180));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::DOWN :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 0)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 0));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        }

    if (playerNbr == 2 && id == 1 && direction != game::Direction::STAY)
        switch (direction) {
        case game::Direction::RIGHT :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 90)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 90));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::LEFT :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, -90)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, -90));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::UP :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 180)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 180));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::DOWN :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 0)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 0));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        }

    if (direction != game::Direction::STAY)
        switch (direction) {
        case game::Direction::RIGHT :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 90)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 90));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::LEFT :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, -90)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, -90));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::UP :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 180)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 180));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        case game::Direction::DOWN :
            if (_players[id]->getNode()->getRotation() != irr::core::vector3df(-90, 0, 0)) {
                _players[id]->getNode()->setRotation(irr::core::vector3df(-90, 0, 0));
                _players[id]->getNode()->setFrameLoop(140, 160);
            }
            return;
        }
}

void graph::Game::updateMap(std::vector<std::vector<game::GameObject *>> map, irr::IrrlichtDevice *window) noexcept
{
    int x = 0;
    int y = 0;
    double posx = 0;
    double posy = 0;
    game::BonusEffect bonus;
    bool explose;

    for (auto i = 0; i != map.size(); ++i, ++y, x = 0)
        for (auto j = 0; j != map[i].size(); ++j, ++x) {
            posx = x * 2.0;
            posy = -y * 2.0;
            switch (map[i][j]->getType()) {
                case game::BOMB :
                    if (_cubes[i][j] == nullptr) {
                        _cubes[i][j] = window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                            irr::core::vector3df(posx, posy, 0.0f));
                        _cubes[i][j]->setVisible(true);
                    }
                    explose = (bool)(dynamic_cast<game::Bomb *>(map[i][j])->AnimExplose());
                    if (explose == true)
                        _cubes[i][j]->setMaterialTexture(0, _textures["explosion"]);
                    else
                        _cubes[i][j]->setMaterialTexture(0, _textures["bomb"]);
                    break;
                case game::GROUND :
                    if (_cubes[i][j] != nullptr) {
                        _cubes[i][j]->remove();
                        _cubes[i][j] = nullptr;
                    }
                    break;
                case game::BONUS :
                    if (_cubes[i][j] != nullptr) {
                        bonus = dynamic_cast<game::Bonus *>(map[i][j])->getBonus();
                        switch (bonus) {
                            case game::BonusEffect::BOMBUP :
                                _cubes[i][j]->setMaterialTexture(0, _textures["bombUp"]);
                                break;
                            case game::BonusEffect::FIRE :
                                _cubes[i][j]->setMaterialTexture(0, _textures["fireUp"]);
                                break;
                            case game::BonusEffect::SPEED :
                                _cubes[i][j]->setMaterialTexture(0, _textures["speedUp"]);
                                break;
                            case game::BonusEffect::WALLPASS :
                                _cubes[i][j]->setMaterialTexture(0, _textures["wallPass"]);
                                break;
                        }
                        _cubes[i][j]->setVisible(true);
                    }
                    break;
            }
        }
}

void graph::Game::updatePlayers(std::vector<game::PlayerObject *> players) noexcept
{
    for (auto i = 0; i != players.size(); ++i)
        if (_players[i] != nullptr && players[i]->isAlive() == false) {
            _players[i]->getNode()->remove();
            _players[i] = nullptr;
        }
}