//
// Created by vhais on 12/6/23.
//

#include "Game.h"
#include <vector>

Game::Game(int boardSize) : board(Board(boardSize)) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distributionClusters(1, boardSize);
    std::uniform_int_distribution<int> distributionClusterSize(1, 3);
    std::uniform_int_distribution<int> distributionPosition(-1, 1);
    int numberOfClustersToGenerate = distributionClusters(gen);
    while (numberOfClustersToGenerate > 0) {
        GenerateCluster(gen, distributionClusterSize(gen));
        numberOfClustersToGenerate--;
    }
    std::cout << "Done initializing\n";
}

void Game::GenerateCluster(std::mt19937 gen, int clusterSize) {
    vector<vector<int>> positions = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
    };
    while (!positions.empty() && clusterSize > 0) {
        int row;
        int col;
        if (positions.size() > 4) {
            std::uniform_int_distribution<int> distribution(0, static_cast<int>(positions.size())-1);
            int index = distribution(gen);
            row = positions[index][0];
            col = positions[index][1];
            positions.erase(positions.begin() + index);
        } else {
            row = positions[0][0];
            col = positions[0][1];
            positions.erase(positions.begin());
        }
        if (row >= 0 && row < board.GetBoardSize() && col >= 0 && col < board.GetBoardSize()) {
            Cell *cell = board.GetCell(row, col);
            if (!cell->IsAlive()) {
                clusterSize--;
                cell->ChangeState();
                aliveCells++;
            }
        }
    }
}

void Game::NextGeneration() {
    for (int i = 0; i < board.GetBoardSize(); i++) {
        for (int j = 0; j < board.GetBoardSize(); j++) {
            Cell* cell = board.GetCell(i, j);
            if (cell->IsAlive()) {
                if (cell->NumberOfAliveNeighbors() < 2 || cell->NumberOfAliveNeighbors() > 3) {
                    stateObserver.subscribe(cell);
                    aliveCells--;
                }
            } else {
                if (cell->NumberOfAliveNeighbors() == 3) {
                    stateObserver.subscribe(cell);
                    aliveCells++;
                }
            }
        }
    }
}

void Game::Play() {
    int turnsElapsed = 0;
    while (aliveCells > 0) {
        NextGeneration();
        if (turnsElapsed > 10) {
            break;
        }
        turnsElapsed++;
    }
    std::cout << "Generations elapsed: " << turnsElapsed << '\n';
}
