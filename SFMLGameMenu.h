//
// Created by sadow on 24.02.2023.
//

/*  Obowiązki:
 * Wyświetlenie menu w oknie sfml
 * Dostarcza klasie Board parametr LEVEL
 */

#ifndef SAPER_SFMLGAMEMENU_H
#define SAPER_SFMLGAMEMENU_H

#include <SFML/Graphics.hpp>

enum LEVEL {Easy,Normal,Hard,Debug};

class SFMLGameMenu {

public:

    LEVEL menu();
    void drawField(sf::RenderWindow & window, sf::Font & font);
    LEVEL clickToChoose(sf::RenderWindow & window);
    void Background(sf::RenderWindow & window);

};


#endif //SAPER_SFMLGAMEMENU_H
