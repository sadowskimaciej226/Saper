//
// Created by sadow on 05.04.2023.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H

#include "Board.h"
#include "SFML_Board.h"

class MSSFMLController {

    MinesweeperBoard & b;
    MSSFMLView & b1;

public:
    MSSFMLController(MinesweeperBoard & board, MSSFMLView & Sfmlboard);
    void play();
};


#endif //SAPER_MSSFMLCONTROLLER_H
