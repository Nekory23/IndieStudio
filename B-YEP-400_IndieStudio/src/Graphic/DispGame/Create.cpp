/*
** EPITECH PROJECT, 2021
** B-YEP_IndieStudio
** File description:
** CreateMap
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

void graph::Game::createBlock(std::vector<std::vector<game::GameObject *>> map, irr::IrrlichtDevice *window) noexcept
{
    std::vector<irr::scene::ISceneNode *> tmp;
    std::vector<irr::scene::ISceneNode *> floorTmp;
    int x = 0;
    int y = 0;
    double posx = 0;
    double posy = 0;
    bool created = false;
    game::BonusEffect bonus;
    bool explose;

    for (auto i = 0; i != map.size(); ++i, ++y, x = 0) {
        for (auto j = 0; j != map[i].size(); ++j, ++x, created = false) {
            posx = x * 2.0;
            posy = -y * 2.0;
            switch (map[i][j]->getType()) {
                case game::WALL :
                    tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                                irr::core::vector3df(posx, posy, 0.0f)));
                    tmp.back()->setMaterialTexture(0, _textures["redBricks"]);
                    created = true;
                    break;
                case game::BRICK :
                    tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                                irr::core::vector3df(posx, posy, 0.0f)));
                    tmp.back()->setMaterialTexture(0, _textures["woodenFloor"]);
                    created = true;
                    break;
                case game::BOMB :
                    tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                            irr::core::vector3df(posx, posy, 0.0f)));
                    if (explose == true)
                        tmp.back()->setMaterialTexture(0, _textures["explosion"]);
                    else
                        tmp.back()->setMaterialTexture(0, _textures["bomb"]);
                    break;
                case game::BONUS :
                    tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                                irr::core::vector3df(posx, posy, 0.0f)));
                    bonus = dynamic_cast<game::Bonus *>(map[i][j])->getBonus();
                    switch (bonus) {
                            case game::BonusEffect::BOMBUP :
                                tmp.back()->setMaterialTexture(0, _textures["bombUp"]);
                                break;
                            case game::BonusEffect::FIRE :
                                tmp.back()->setMaterialTexture(0, _textures["fireUp"]);
                                break;
                            case game::BonusEffect::SPEED :
                                tmp.back()->setMaterialTexture(0, _textures["speedUp"]);
                                break;
                            case game::BonusEffect::WALLPASS :
                                tmp.back()->setMaterialTexture(0, _textures["wallPass"]);
                                break;
                        }
                    break;
            }
            if (created)
                tmp.back()->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            else
                tmp.push_back(nullptr);
            floorTmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                            irr::core::vector3df(posx, posy, 1.0f)));
            floorTmp.back()->setMaterialTexture(0, _textures["grass"]);
            floorTmp.back()->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        }
        _cubes.push_back(tmp);
        _floor.push_back(floorTmp);
        tmp.clear();
        floorTmp.clear();
    }
}

void graph::Game::createPlayers(std::vector<game::PlayerObject *> players, irr::IrrlichtDevice *window, int nbr) noexcept
{
    int x = 0;
    int y = 0;
    int rotation = 0;
    std::vector<std::string> names;

    if (nbr == 1) {
        names.push_back("player 1");
        names.push_back("ai 1");
        names.push_back("ai 2");
        names.push_back("ai 3");
    }
    else {
        names.push_back("player 1");
        names.push_back("player 2");
        names.push_back("ai 1");
        names.push_back("ai 2");
    }
    for (std::size_t i = 0; i != players.size(); ++i, rotation += 90) {
        x = convertToX(players[i]->getX());
        y = convertToY(players[i]->getY());
        _players.push_back(new Player(window, rotation, x, y, names[i]));
    }
}