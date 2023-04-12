

#ifndef SAPER_BOARD_H
#define SAPER_BOARD_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"SFMLGameMenu.h"
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
    void SetSize(GameMode HowHard);
    void SetMine();


public:
    int getwidth() const;
    int getheight() const;
    GameMode getLevel();
    MinesweeperBoard(int width, int height, GameMode level);
    explicit MinesweeperBoard(SFMLGameMenu & menu); // za pomocą tych pomocniczych zmiennych ustawie w konstruktorze wielkość planszy

    void DebugDisplay();
    bool RevealdField(int row, int col);
    bool ToggleFlag(int row, int col);
    //void ChangeMinePos(int width, int height); na razie nie potrzebne
    char countMines(int row, int col) const;
    char FieldInfo(int row, int col) const; // funkcja bedzie zwracać znak w zależności jaki jest stan pola
    STAN getGameState() const;
    //LEVEL chooseLevel();
    // WAŻNE!!!! należy dodać opcje która zresetuje gre gdy przy pierwszym ruchu wylosujemy bombe
};




#endif //SAPER_BOARD_H
