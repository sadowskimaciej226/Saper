#include "SFML_Board.h"
#include <string>
MSSFMLView::MSSFMLView(MinesweeperBoard & board, SFMLGameMenu & menu) : b1(board), m1(menu)
{

}

void MSSFMLView::View() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");
    window.setFramerateLimit(60);

    sf::RectangleShape Field(sf::Vector2f(25,25));
    Field.setFillColor(sf::Color{150,150,150});

    GameMode level=b1.getLevel();

    sf::Font font;
    if(!font.loadFromFile("C:/WINDOWS/FONTS/arial.ttf"))
        abort();


    sf::Texture Flag;
    if (!Flag.loadFromFile("C:/Users/sadow/Downloads/5741911.png"))
    {
        std::cout<<"Problem with photo";
        abort();
    }

    sf::Texture Bomb;
    if (!Bomb.loadFromFile("C:/Users/sadow/Downloads/ae0d1e80-6f46-11e9-96b3-b7757a65a1c7.gif")) {
        std::cout << "Problem with load photo";
        abort();
    }

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        m1.Background(window);

        SetField(window,level,Field,font,Flag,Bomb);

        window.display();
    }
}
//function loadsa picture of the Flag, sets Flag positions and draws it
void MSSFMLView::showFlag(sf::RenderWindow &window,GameMode level,const int width,const int height,sf::Texture & texture) {
    //https://www.flaticon.com/free-icon/destination_5741911


    sf::Sprite sprite;

    sprite.setTexture(texture);
    sprite.setScale(0.05,0.05);

    int a= SFMLwidth(level,width);
    int b= SFMLheight(height);



    sprite.setPosition(a,b);

    window.draw(sprite);

}

//function loads a picture of the all Bombs if Player lose a game and draws it
bool MSSFMLView::showBomb(sf::RenderWindow &window,GameMode level,int width,int height,sf::Texture & texture) {
//https://github.com/topics/minesweeper-style-game?o=asc&s=stars



    sf::Sprite sprite;

        sprite.setTexture(texture);
        sprite.setScale(0.3, 0.3);

        int a = SFMLwidth(level, width)-18;
        int b = SFMLheight(height)-15;


        sprite.setPosition(a, b);

        window.draw(sprite);
        return true;
}

bool MSSFMLView::MineCount(sf::RenderWindow &window, GameMode level, int width, int height,sf::Font & font) {

    sf::String s;
    s=b1.FieldInfo(width,height);

   sf::Text MineNum;
    MineNum.setFont(font);

    int a= SFMLwidth(level,width);
    int b= SFMLheight(height);
    MineNum.setPosition(a+5,b);
    MineNum.setCharacterSize(25);

    MineNum.setFillColor(sf::Color{120,200,130});
    MineNum.setString(s);
    window.draw(MineNum);

    return true;

}

//funcion draw all field and set their position using game level, moreover function use functions show flag show bomb
void MSSFMLView::SetField(sf::RenderWindow & window, GameMode level,sf::RectangleShape & field,sf::Font & font,sf::Texture & Flag,sf::Texture & Bomb) {

    for(int i=0;i<b1.getheight();i++){
        for(int j=0;j<b1.getwidth();j++) {

            field.setPosition(SFMLwidth(level, j), SFMLheight(i));
            window.draw(field);
            if (b1.FieldInfo(j, i) == 70)
                showFlag(window,level,j,i, Flag);

            if (b1.FieldInfo(j, i) >=48 && b1.FieldInfo(j, i) <=56)
            MineCount(window,level,j,i,font);

            if (b1.FieldInfo(j,i)==88)
                showBomb(window,level,j,i,Bomb);
        }
    }
}

//using game level, funcion return width where we want to draw something
int MSSFMLView::SFMLwidth(GameMode level,int width) {
    int a;
    if(level==Easy) {
        a=30*width+250;
    }
    if(level==Normal) {
        a=30*width+200;
    }
    if(level==Hard) {
        a=30*width+150;
    }
    return a;
}

int MSSFMLView::SFMLheight(int height) {
    return 30*height+100;
}