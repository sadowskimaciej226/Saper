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


class GameManager {
    Board & b1;
    Player & p1;
public:
    GameManager(Board & board, Player & player);
    void Play();
    void saveToFile();
};


#endif //SAPER_GAMEMANAGER_H
