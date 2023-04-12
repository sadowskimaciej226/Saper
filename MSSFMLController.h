//
// Created by sadow on 05.04.2023.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H

#include "Board.h"
#include "SFML_Board.h"

class MSSFMLController {

    Board & b;
    SFML_Board & b1;

public:
    MSSFMLController(Board & board, SFML_Board & Sfmlboard);
    void play();
};


#endif //SAPER_MSSFMLCONTROLLER_H
