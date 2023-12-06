//
// Created by vhais on 12/6/23.
//

#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H
#include <vector>
#include "Cell.h"

using std::vector;

class Board {
private:
    int boardSize;
    Cell*** cells;
    const vector<vector<int>> neighborPositions = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
    };
    void AddNeighborsToCell(int row, int col);
    void AddNeighborToCell(Cell* cell, int row, int col);
public:
    explicit Board(int size);
    [[nodiscard]] Cell* GetCell(int row, int col) const;
    [[nodiscard]] int GetBoardSize() const;
};


#endif //GAMEOFLIFE_BOARD_H
