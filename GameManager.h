//
// Created by sadow on 22.02.2023.
//

/* Obowiązki:
 * Prowadzenie rozgrywki
 * Tworzenie zapisu do gry
 * Chyba all :)
 */

#ifndef SAPER_GAMEMANAGER_H
#define SAPER_GAMEMANAGER_H

#include"Board.h"
#include"Player.h"


class MSTextController {
    MinesweeperBoard & b1;
    Player & p1;
    void Board_view();
public:
    MSTextController(MinesweeperBoard & board, Player & player);
    void Play();

};


#endif //SAPER_GAMEMANAGER_H
