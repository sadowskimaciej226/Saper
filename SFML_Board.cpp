#include "SFML_Board.h"
#include <string>
SFML_Board::SFML_Board(MinesweeperBoard & board, SFMLGameMenu & menu) : b1(board), m1(menu)
{

}

void SFML_Board::DrawBoard() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");
    window.setFramerateLimit(60);

    sf::RectangleShape Field(sf::Vector2f(25,25));
    Field.setFillColor(sf::Color{150,150,150});

    LEVEL level=b1.getLevel();

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
void SFML_Board::showFlag(sf::RenderWindow &window,LEVEL level,const int width,const int height,sf::Texture & texture) {
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
bool SFML_Board::showBomb(sf::RenderWindow &window,LEVEL level,int width,int height,sf::Texture & texture) {
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

bool SFML_Board::MineCount(sf::RenderWindow &window, LEVEL level, int width, int height,sf::Font & font) {



    sf::Text MineNum;
    MineNum.setFont(font);
    //MineNum.setFillColor(sf::Color{255,255,255,255});
    int a= SFMLwidth(level,width);
    int b= SFMLheight(height);
    MineNum.setPosition(a+5,b);
    MineNum.setCharacterSize(25);
    if(b1.FieldInfo(width,height)==48){
        MineNum.setFillColor(sf::Color{120,200,130});
        MineNum.setString("0");
        window.draw(MineNum);

        return true;
    }
    if(b1.FieldInfo(width,height)==49){
        MineNum.setFillColor(sf::Color{120,150,100});
        MineNum.setString("1");
        window.draw(MineNum);

        return true;
    }
    if(b1.FieldInfo(width,height)==50){
        MineNum.setFillColor(sf::Color{140,140,100});
        MineNum.setString("2");
        window.draw(MineNum);
        return true;
    }
    if(b1.FieldInfo(width,height)==51){
        MineNum.setFillColor(sf::Color{160,130,100});
        MineNum.setString("3");
        window.draw(MineNum);
        return true;
    }
    if(b1.FieldInfo(width,height)==52){
        MineNum.setFillColor(sf::Color{180,120,100});
        MineNum.setString("4");
        window.draw(MineNum);
        return true;
    }
    if(b1.FieldInfo(width,height)==53){
        MineNum.setFillColor(sf::Color{200,100,100});
        MineNum.setString("5");
        window.draw(MineNum);
        return true;
    }
    if(b1.FieldInfo(width,height)==54){
        MineNum.setFillColor(sf::Color{220,100,100});
        MineNum.setString("6");
        window.draw(MineNum);
        return true;
    }
    if(b1.FieldInfo(width,height)==55){
        MineNum.setFillColor(sf::Color{240,100,100});
        MineNum.setString("7");
        window.draw(MineNum);
        return true;
    }
    if(b1.FieldInfo(width,height)==56){
        MineNum.setFillColor(sf::Color{255,100,100});
        MineNum.setString("8");
        window.draw(MineNum);
        return true;
    }

    return false;
}

//funcion draw all field and set their position using game level, moreover function use functions show flag show bomb
void SFML_Board::SetField(sf::RenderWindow & window, LEVEL level,sf::RectangleShape & field,sf::Font & font,sf::Texture & Flag,sf::Texture & Bomb) {

    for(int i=0;i<b1.getheight();i++){
        for(int j=0;j<b1.getwidth();j++) {

            field.setPosition(SFMLwidth(level, j), SFMLheight(i));
            window.draw(field);
            if (b1.FieldInfo(j, i) == 70)
                showFlag(window,level,j,i, Flag);


            MineCount(window,level,j,i,font);

            if (b1.FieldInfo(j,i)==88)
                showBomb(window,level,j,i,Bomb);
        }
    }
}

//using game level funcion return width where we want to draw something
int SFML_Board::SFMLwidth(LEVEL level,int width) {
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

int SFML_Board::SFMLheight(int height) {
    return 30*height+100;
}