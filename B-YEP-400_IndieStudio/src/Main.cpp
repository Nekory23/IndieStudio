/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Main
*/

#include "Indie.hpp"
#include "Graphic.hpp"
#include "Game.hpp"
#include "Menu.hpp"

static void manageControls(graph::Graphic *graph, game::Bomberman *game)
{
    game->setDirectionPlayer(0, graph->getDirectionPlayerOne());
        if (graph->getActionPlayerOne())
            game->layBombPlayer(0);
        if (graph->getPlayerNumber() == 2) {
            game->setDirectionPlayer(1, graph->getDirectionPlayerTwo());
            if (graph->getActionPlayerTwo())
                game->layBombPlayer(1);
        }
        game->playerManagement();
        game->AIManagement();
}

static void updatePositions(graph::Graphic *graph, game::Bomberman *game)
{
    if (graph->getGame() != nullptr) {
        graph->setNewPlayerPositions(0, game->getPlayers(), graph->getDirectionPlayerOne());
        if (graph->getPlayerNumber() == 2)
            graph->setNewPlayerPositions(1, game->getPlayers(), graph->getDirectionPlayerTwo());
        else 
            graph->setNewPlayerPositions(1, game->getPlayers(), game->getPlayers()[1]->getDirection());
        graph->setNewPlayerPositions(2, game->getPlayers(), game->getPlayers()[2]->getDirection());
        graph->setNewPlayerPositions(3, game->getPlayers(), game->getPlayers()[3]->getDirection());
    }
}

int main()
{
    graph::Graphic graph;
    game::Bomberman game;
    int ret = 0;
    bool over = false;

    while (graph.getIsOpen()) {
        if (graph.getLoad() == true) {
            game.setLoad(graph.getLoad());
            graph.setLoad(false);
            if (game.reset() == 84)
                return 84;
            graph.setPlayerNumber(game.getPlayerNbr());
            game.setLoad(false);
        }
        if (graph.getPlayerNumber() == 0 || over) {
            ret = graph.display(game.getMap(), game.getPlayers());
            if (ret == -1)
                break;
            if (ret == -2) {
                over = false;
                graph.setState(graph::stateGraph::MENU);
                graph.getMenu()->setState(graph::menuState::MAIN);
                graph.setPlayerNumber(0);
                if (game.reset() == 84)
                    return 84;
            }
            continue;
        }
        game.setPlayerNbr(graph.getPlayerNumber());
        ret = graph.display(game.getMap(), game.getPlayers());
        if (graph.getState() == graph::stateGraph::PAUSE)
            continue;
        if (ret == -1)
            break;
        if (game.gameover()) {
            over = true;
            graph.setState(graph::stateGraph::OVER);
            continue;
        }
        if (ret < -1) {
            if (graph.getSave()) {
                game.save();
                graph.setSave(false);
            }
            game.reset();
            graph.setPlayerNumber(0);
            continue;
        }
        manageControls(&graph, &game);
        updatePositions(&graph, &game);
        game.explosion();
    }
    return SUCCESS;
}