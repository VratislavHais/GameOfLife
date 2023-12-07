//
// Created by vhais on 12/6/23.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H
#include "Board.h"
#include "StateObserver.h"
#include "Printer.h"
#include <random>
#include <thread>
#include <chrono>

class Game {
private:
    const Board board;
    StateObserver stateObserver = StateObserver{};
    const Printer printer;
    int aliveCells{0};
    void NextGeneration();
    void GenerateCluster(std::mt19937 gen, int clusterSize, int rootRow, int rootCol);
public:
    explicit Game(int boardSize);
    void Play();
};


#endif //GAMEOFLIFE_GAME_H
