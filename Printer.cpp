//
// Created by vhais on 12/7/23.
//

#include "Printer.h"
#include <iostream>

using std::cout;

Printer::Printer(const Board* board) : board(board) {

}

void Printer::printGeneration() const {
    Clear();
    int boardSize = board->GetBoardSize();
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board->GetCell(i, j)->IsAlive()) {
                cout << aliveChar;
            } else {
                cout << deadChar;
            }
        }
        cout << std::endl;
    }
}

void Printer::Clear() {
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}
