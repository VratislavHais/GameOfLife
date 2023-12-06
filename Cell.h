//
// Created by vhais on 12/6/23.
//

#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H
#include <vector>

class Cell {
private:
    bool alive = false;
    int aliveNeighbors{0};
    std::vector<Cell*> neighbors;
public:
    void ChangeState();
    [[nodiscard]] bool IsAlive() const;
    void AddNeighbor(Cell *neighbor);
    void AddAliveNeighbor();
    void RemoveAliveNeighbor();
    [[nodiscard]] int NumberOfAliveNeighbors() const;
};


#endif //GAMEOFLIFE_CELL_H
