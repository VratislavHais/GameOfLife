//
// Created by vhais on 12/6/23.
//

#include "Game.h"
#include <vector>

Game::Game(int boardSize) : board(Board(boardSize)), printer(Printer(&board)) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distributionBoardSize(1, boardSize);
    std::uniform_int_distribution<int> distributionClusterSize(3, 9);
    std::uniform_int_distribution<int> distributionPosition(-1, 1);
    int numberOfClustersToGenerate = distributionBoardSize(gen) * 2;
    while (numberOfClustersToGenerate > 0) {
        GenerateCluster(gen, distributionClusterSize(gen), distributionBoardSize(gen), distributionBoardSize(gen));
        numberOfClustersToGenerate--;
    }
}

void Game::GenerateCluster(std::mt19937 gen, int clusterSize, int rootRow, int rootCol) {
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
            row = rootRow + positions[index][0];
            col = rootCol + positions[index][1];
            positions.erase(positions.begin() + index);
        } else {
            row = rootRow + positions[0][0];
            col = rootCol + positions[0][1];
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
    stateObserver.execute();
}

void Game::Play() {
    while (aliveCells > 0) {
        NextGeneration();
        printer.printGeneration();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
