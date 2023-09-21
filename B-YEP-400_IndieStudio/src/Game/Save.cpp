/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Save
*/

#include "Game.hpp"
#include <fstream>
#include <iostream>

void game::Bomberman::save(void) noexcept {
    std::string map("./save/map.txt");
    std::string players("./save/players.txt");
    std::fstream map_file_out;
    std::fstream players_file_out;
    std::string tab = convertToString();

    map_file_out.open(map, std::ios_base::out);
    players_file_out.open(players, std::ios_base::out);
    map_file_out << tab;
    for (int i = 0; i < 4; i++) {
        players_file_out << _players[i]->isAlive() << std::endl;
        players_file_out << _players[i]->getBombNbr() << std::endl;
        players_file_out << _players[i]->getSpeed() << std::endl;
        players_file_out << _players[i]->getPower() << std::endl;
        players_file_out << _players[i]->getWallPass() << std::endl;
        players_file_out << _players[i]->getX() << std::endl;
        players_file_out << _players[i]->getY() << std::endl;
        players_file_out << _players[i]->getStock() << std::endl;
    }
    players_file_out << "." << _playerNbr << std::endl;
    map_file_out.close();
    players_file_out.close();
}

int game::Bomberman::loadMap(void) noexcept
{
    std::string str;
    std::ifstream fichier("./save/map.txt");

    _map.clear();
    if(fichier.is_open())
    {
        while(std::getline(fichier, str)) {
            _map.push_back(str);
            str.clear();
        }
        fichier.close();
        _size_l = _map.size();
        _size_L = _map[0].length();
    } else {
        std::cerr << "No such file or directory" << std::endl;
        return (84);
    }
    convertToObject();
    return (0);
}

int game::Bomberman::loadPlayers(void) noexcept
{
    int i = 0;
    int n = 0;
    int nb = 0;
    std::string str;
    std::ifstream fichier("./save/players.txt");

    if(fichier.is_open())
    {
        _players.clear();
        createPlayers();
        while(std::getline(fichier, str)) {
            if (str.find('.') != str.npos) {
                str.erase(0, 1);
                _playerNbr = std::stoi(str);
            } else {
                if (n == 0)
                    _players[i]->setAlive(std::stoi(str));
                if (n == 1)
                    _players[i]->setBombNbr(std::stoi(str));
                if (n == 2)
                    _players[i]->setSpeed(std::stoi(str));
                if (n == 3)
                    _players[i]->setPower(std::stoi(str));
                if (n == 4)
                    _players[i]->setWallPass((bool)(std::stoi(str)));
                if (n == 5)
                    _players[i]->setX(std::stof(str));
                if (n == 6)
                    _players[i]->setY(std::stof(str));
                if (n == 7) {
                    _players[i]->setStock(std::stoi(str));
                    i++;
                    n = 0;
                } else
                    n++;
            }
            str.clear();
        }
        fichier.close();
    } else {
        std::cerr << "No such file or directory" << std::endl;
        return (84);
    }
    return (0);
}