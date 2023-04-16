//
// Created by sadow on 05.04.2023.
//

#include "MSSFMLController.h"
#include <iostream>
MSSFMLController::MSSFMLController(MinesweeperBoard & board, MSSFMLView &Sfmlboard) : B(board), G(Sfmlboard)
{

}

void MSSFMLController::play() {

    sf::RenderWindow window(sf::VideoMode(get_window_width(), get_window_height()), "Saper");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    while (window.isOpen()) {
        sf::Event event{};


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


       if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
       {
           B.RevealdField(get_row_number(window), get_col_number(window));
       }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            B.ToggleFlag(get_row_number(window), get_col_number(window));
        }


        G.View(window);
       window.display();

    }
}

int MSSFMLController::get_window_width() const {
    return 150+G.Field_width(B.getwidth());
}

int MSSFMLController::get_window_height() const {
    return 30+G.Field_height(B.getheight());
}

int MSSFMLController::get_col_number(sf::RenderWindow & window) const {
    int px= sf::Mouse::getPosition(window).x;
    int row=(px-150)/30;
    return row;
}

int MSSFMLController::get_row_number(sf::RenderWindow &window) const {
    int py= sf::Mouse::getPosition(window).y;
    int col=(py-30)/30;
    return col;
}



