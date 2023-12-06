//
// Created by vhais on 12/6/23.
//

#include "Cell.h"

void Cell::ChangeState() {
    alive = !alive;
    for (Cell* neighbor : neighbors) {
        if (alive) {
            neighbor->AddAliveNeighbor();
        } else {
            neighbor->RemoveAliveNeighbor();
        }
    }
}

bool Cell::IsAlive() const {
    return alive;
}

void Cell::AddAliveNeighbor() {
    aliveNeighbors++;
}

void Cell::RemoveAliveNeighbor() {
    aliveNeighbors--;
}

void Cell::AddNeighbor(Cell *neighbor) {
    neighbors.push_back(neighbor);
}

int Cell::NumberOfAliveNeighbors() const {
    return aliveNeighbors;
}
