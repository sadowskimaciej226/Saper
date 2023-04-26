//
// Created by sadow on 05.04.2023.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H

#include "Board.h"
#include "SFML_Board.h"

class MSSFMLController {

    MinesweeperBoard & B;
    MSSFMLView & G;
    int get_window_width() const;
    int get_window_height() const;
    int get_col_number(sf::RenderWindow & window) const;
    int get_row_number(sf::RenderWindow & window) const;

public:
    MSSFMLController(MinesweeperBoard & board, MSSFMLView & Sfmlboard);
    void play();
};


#endif //SAPER_MSSFMLCONTROLLER_H
