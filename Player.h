//
// Created by sadow on 22.02.2023.
//

#ifndef SAPER_PLAYER_H
#define SAPER_PLAYER_H

#include"Board.h"
/*
 * odpowiedzialność:
 * zaznaczanie flag
 * odkrywanie pol
 * chyba all :)
 */

class Player {
    Board & b;

public:
    explicit Player(Board & board);
    void RevealField();
    void ToggleFlag();
};


#endif //SAPER_PLAYER_H
