//
// Created by vhais on 12/6/23.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H
#include "Board.h"
#include "StateObserver.h"
#include <random>

class Game {
private:
    const Board board;
    StateObserver stateObserver = StateObserver{};
    int aliveCells{0};
    void NextGeneration();
    void GenerateCluster(std::mt19937 gen, int clusterSize);
public:
    explicit Game(int boardSize);
    void Play();
};


#endif //GAMEOFLIFE_GAME_H
