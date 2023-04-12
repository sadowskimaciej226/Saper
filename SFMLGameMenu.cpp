
#include "SFMLGameMenu.h"
#include <iostream>

GameMode SFMLGameMenu::menu() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Saper");

    sf::RectangleShape Win(sf::Vector2f(800,600));
    Win.setFillColor(sf::Color{210,210,210});

    //font do tekstu
    sf::Font font;
    if(!font.loadFromFile("C:/WINDOWS/FONTS/arial.ttf"))
        abort();

    GameMode option;
    while(window.isOpen()){
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //window.draw(Win);
        Background(window);
        drawField(window, font);
        option= clickToChoose(window);
        window.display();
        if(option!=Debug) {

            return option;
        }
    }
    return Debug;
}

void SFMLGameMenu::drawField(sf::RenderWindow & window, sf::Font & font) {



    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color{255,255,255,255});

    sf::Text text1;
    text1.setFont(font);
    text1.setFillColor(sf::Color::White);

    text1.setPosition(210,110);
    text1.setString("Welcome in MineSwepper");
    window.draw(text1);

    text1.setPosition(200,150);
    text1.setString("Please choose level to play");
    window.draw(text1);

    sf::RectangleShape field(sf::Vector2f(130,60));
    field.setFillColor(sf::Color{50,50,50});

    for(int i=0;i<3;i++){

            field.setPosition(180+(i*155),310);
            window.draw(field);

            if(i==0){
                text.setString("EASY");
                text.setPosition(205+(i*150), 320);
                window.draw(text);
            }
            if(i==1){
                text.setString("NORMAL");
                text.setPosition(186+(i*150), 320);
                window.draw(text);
            }
            if(i==2){
            text.setString("HARD");
            text.setPosition(215+(i*150), 320);
            window.draw(text);
            }

    }
}

GameMode SFMLGameMenu::clickToChoose(sf::RenderWindow &window) {

   int px=sf::Mouse::getPosition(window).x;
   int py=sf::Mouse::getPosition(window).y;
   // std::cout<<"px="<<px<<" py="<<py<<std::endl;

    if(px>=180&&px<310&&py>=310&&py<=370){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            return Easy;
        }
    }

    if(px>=335&&px<=465&&py>=310&&py<=370)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            return Normal;
        }
    }

    if(px>=490&&px<=620&&py>=310&&py<=370)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            return Hard;
        }
    }

  return Debug;
}

void SFMLGameMenu::Background(sf::RenderWindow & window) {

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/sadow/Downloads/free_city_of_war_background_by_qasimshoukat786_dbz3evz-fullview.jpg"))
    {
        std::cout<<"Problem ze zdj sry";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);
}


