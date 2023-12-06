//
// Created by vhais on 12/6/23.
//

#ifndef GAMEOFLIFE_STATEOBSERVER_H
#define GAMEOFLIFE_STATEOBSERVER_H
#include <iostream>
#include <stack>
#include "Cell.h"

class StateObserver {
private:
    std::stack<Cell*> subscribed;
public:
    void subscribe(Cell* cell);
    void execute();
};


#endif //GAMEOFLIFE_STATEOBSERVER_H
