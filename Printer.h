//
// Created by vhais on 12/7/23.
//

#ifndef GAMEOFLIFE_PRINTER_H
#define GAMEOFLIFE_PRINTER_H
#include "Board.h"

class Printer {
private:
    const Board* board;
    const char aliveChar = static_cast<char>(0x2588);
    const char deadChar = '.';
    static void Clear() ;
public:
    explicit Printer(const Board* board);
    void printGeneration() const;
};


#endif //GAMEOFLIFE_PRINTER_H
