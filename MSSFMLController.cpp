//
// Created by sadow on 05.04.2023.
//

#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(MinesweeperBoard & board, SFML_Board &Sfmlboard) : b(board), b1(Sfmlboard)
{

}

void MSSFMLController::play() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");

    while (window.isOpen()) {
        sf::Event event{};


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }



    }

    }
