//
// Created by vhais on 12/6/23.
//

#include "StateObserver.h"

void StateObserver::subscribe(Cell* cell) {
    subscribed.push(cell);
}

void StateObserver::execute() {
    while (!subscribed.empty()) {
        subscribed.top()->ChangeState();
        subscribed.pop();
    }
}
