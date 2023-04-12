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
class MSSFMLView {
    MinesweeperBoard & b1;
    SFMLGameMenu & m1;
    void showFlag(sf::RenderWindow & window,GameMode level, int width, int height,sf::Texture & Flag);
    bool showBomb(sf::RenderWindow & window,GameMode level,int width,int height,sf::Texture & Bomb);
    bool MineCount(sf::RenderWindow & window,GameMode level,int width,int height, sf::Font & font);
    void SetField(sf::RenderWindow & window, GameMode level,sf::RectangleShape & field,sf::Font & font,sf::Texture & Flag,sf::Texture & Bomb);
    int SFMLwidth(GameMode level,int width);
    int SFMLheight(int height);
public:
    MSSFMLView(MinesweeperBoard & board, SFMLGameMenu & menu);
    void View();


};

#endif //SAPER_SFML_BOARD_H
