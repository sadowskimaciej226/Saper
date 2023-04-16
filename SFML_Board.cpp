#include "SFML_Board.h"
#include <string>
MSSFMLView::MSSFMLView(MinesweeperBoard & board) : b1(board)
{

}

void MSSFMLView::View(sf::RenderWindow & window) {

   /*sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");
    window.setFramerateLimit(60);*/

    sf::RectangleShape Field(sf::Vector2f(25,25));
    Field.setFillColor(sf::Color{150,150,150});



   /* sf::RectangleShape Field(sf::Vector2f(25,25));
    Field.setFillColor(sf::Color{150,150,150});*/



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


        Draw_Background(window);

        SetField(window,Field,font,Flag,Bomb);



}
//function loadsa picture of the Flag, sets Flag positions and draws it
void MSSFMLView::showFlag(sf::RenderWindow &window,const int col,const int row,sf::Texture & texture) {
    //https://www.flaticon.com/free-icon/destination_5741911


    sf::Sprite sprite;

    sprite.setTexture(texture);
    sprite.setScale(0.05,0.05);

    int a= Field_width(col);
    int b= Field_height(row);



    sprite.setPosition(a,b);

    window.draw(sprite);

}

//function loads a picture of the all Bombs if Player lose a game and draws it
bool MSSFMLView::showBomb(sf::RenderWindow &window,int width,int height,sf::Texture & texture) {
//https://github.com/topics/minesweeper-style-game?o=asc&s=stars



    sf::Sprite sprite;

        sprite.setTexture(texture);
        sprite.setScale(0.3, 0.3);

        int a = Field_width(width)-18;
        int b = Field_height(height)-15;


        sprite.setPosition(a, b);

        window.draw(sprite);
        return true;
}

bool MSSFMLView::MineCount(sf::RenderWindow &window, int width, int height,sf::Font & font) {

    sf::String s;
    char s1=b1.FieldInfo(height,width);
    s=s1;

   sf::Text MineNum;
    MineNum.setFont(font);

    int a= Field_width(width);
    int b= Field_height(height);
    MineNum.setPosition(a+3,b-5);
    MineNum.setCharacterSize(25);

    MineNum.setFillColor(sf::Color{250,200,130});
    MineNum.setString(s);

    window.draw(MineNum);

    return true;

}

//funcion draw all field and set their position using game level, moreover function use functions show flag show bomb
void MSSFMLView::SetField(sf::RenderWindow & window,sf::RectangleShape & field,sf::Font & font,sf::Texture & Flag,sf::Texture & Bomb) {

    for(int i=0;i<b1.getheight();i++){
        for(int j=0;j<b1.getwidth();j++) {

            field.setPosition(Field_width( j), Field_height(i));
            window.draw(field);

            if (b1.FieldInfo(i, j) == 70)
                showFlag(window,j,i, Flag);

            if (b1.FieldInfo(i,j)==88)
                showBomb(window,j,i,Bomb);

            if (b1.FieldInfo(i, j) >=48 && b1.FieldInfo(i, j) <=56)
                MineCount(window,j,i,font);
        }
    }
}

//using game level, funcion return width where we want to draw something
int MSSFMLView::Field_width(int width) const{

    return 30*width+150;;
}

 int MSSFMLView::Field_height(int height) const{
    return 30*height+30;
}
void MSSFMLView::Draw_Background(sf::RenderWindow & window) {

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/sadow/Downloads/free_city_of_war_background_by_qasimshoukat786_dbz3evz-fullview.jpg"))
    {
        std::cout<<"ERROR PROBLEM WITH LOADING BACKGROUND";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    window.draw(sprite);

}