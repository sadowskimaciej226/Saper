//
// Created by sadow on 27.02.2023.
//

#ifndef SAPER_SFML_BOARD_H
#define SAPER_SFML_BOARD_H
#include "Board.h"
#include "SFMLGameMenu.h"

/* Obowiązki:
 * Wyświetlanie Flag
 * Wyświetlanie bomb
 * Wyświetlanie czasu (może)
 * Wyświetlanie ilości bomb w okół
 * Wyświetlenie planszy
 * Wyświetlenie wyniku końcowego
 */
class SFML_Board {
    Board & b1;
    SFMLGameMenu & m1;

public:
    SFML_Board(Board & board, SFMLGameMenu & menu);
    void DrawBoard();
    void showFlag(sf::RenderWindow & window,LEVEL level, int width, int height);
    void showBomb(sf::RenderWindow & window,LEVEL level,int width,int height);
    bool MineCount(sf::RenderWindow & window,LEVEL level,int width,int height, sf::Font & font);
    void SetField(sf::RenderWindow & window, LEVEL level,sf::RectangleShape & field,sf::Font & font);
    int SFMLwidth(LEVEL level,int width);
    int SFMLheight(int height);
};

#endif //SAPER_SFML_BOARD_H
