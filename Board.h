

#ifndef SAPER_BOARD_H
#define SAPER_BOARD_H
#include<iostream>
#include<cstdlib>
#include<ctime>
//#include"SFMLGameMenu.h"
//POTRZEBNE FUNKCJE:
/*
 * funkcja ustawiająca miny : SetMine git
 * funkcja odkrywająca pole :RevealdField git
 * funkcja ustawiająca flage : ToggleFlag git
 * funkcja mowiaca o stanie pola "Field info" :FielInfo git
 * funkcja orzekająca czy koniec czy nie :GameStan
 * funkcja ustawiajaca wielkosc planszy w zależności od trudności :SetSize git
 * funkcja sprawiająca ze przy pierwszym odkryciu jesli jest tam mina zmienia sie miejsce miny: ChangeMinePos
 * funkcja sprawdzająca czy dany ruch był pierwszym ruchem jednak dodam zmienną prywatną
 * funkcja licząca miny do okoła: MinesCout
 * funkcja sprawdzająca czy poruszamy się po tablicy
 * coś pewnie jeszcze
 */
enum GameMode {Easy,Normal,Hard,Debug};
enum STAN {Win,Lose,Running};


//struktura która trzyma informacje o danym polu na planszy
struct Field {
    bool HasMine,HasFlag,isReveald;
};
class MinesweeperBoard {
private:
    Field plansza[100][100];
    int width;
    int height;
    GameMode level;
    int MNumber;
    //SFMLGameMenu & menu;
   // bool FirstMove=true; // na pozniej
    void ClearBoard();
    void SetSize(GameMode Diffculty);
    void SetMine();




public:
    int getwidth() const;
    int getheight() const;

    GameMode getLevel();
    MinesweeperBoard(int width, int height, GameMode level);
   // explicit MinesweeperBoard(SFMLGameMenu & menu); // constructor using class SFMLGameMenu to set Board size in SFML

    void DebugDisplay();
    bool RevealdField(int row, int col);
    bool ToggleFlag(int row, int col);

    char countMines(int row, int col) const;
    char FieldInfo(int row, int col) const; // funkcja bedzie zwracać znak w zależności jaki jest stan pola
    STAN getGameState() const;

};




#endif //SAPER_BOARD_H
