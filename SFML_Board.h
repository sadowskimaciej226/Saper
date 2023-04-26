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
    sf::Font font;
    sf::Texture background;
    sf::Texture Bomb;
    sf::Texture Flag;


    void showFlag(sf::RenderWindow & window, int width, int height);
    bool showBomb(sf::RenderWindow & window,int width,int height);
    bool MineCount(sf::RenderWindow & window,int width,int height);
    void SetField(sf::RenderWindow & window,sf::RectangleShape & field);
    void Draw_Background(sf::RenderWindow & win);
    void Lose_Comunication(sf::RenderWindow & win);
    void Won_Comunication(sf::RenderWindow & win);
public:
   int Field_width(int width) const;
   int Field_height(int height) const;
   explicit MSSFMLView(MinesweeperBoard & board);
    void View(sf::RenderWindow & window);


};

#endif //SAPER_SFML_BOARD_H
