//
// Created by vhais on 12/6/23.
//

#include "Board.h"

Board::Board(int size) : boardSize(size) {
    cells = new Cell**[size];
    for (int i = 0; i < size; i++) {
        cells[i] = new Cell*[size];
        for (int j = 0; j < size; j++) {
            cells[i][j] = new Cell();
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            AddNeighborsToCell(i, j);
        }
    }
}

void Board::AddNeighborsToCell(int row, int col) {
    Cell* cell = cells[row][col];
    for (const auto& position : neighborPositions) {
        AddNeighborToCell(cell, row + position[0], col + position[1]);
    }
}

void Board::AddNeighborToCell(Cell* cell, int row, int col) {
    if (row >= 0 && row < boardSize && col >= 0 && col < boardSize) {
        cell->AddNeighbor(cells[row][col]);
    }
}

int Board::GetBoardSize() const {
    return boardSize;
}

Cell *Board::GetCell(int row, int col) const {
    return cells[row][col];
}
