#include "Board.h"
#include <iostream>
using namespace std;

/*MinesweeperBoard::MinesweeperBoard(SFMLGameMenu & m1) : menu(m1)
{

    level=m1.menu();
    if(level==Debug) abort();
    SetSize(level);
    ClearBoard();
    SetMine();

}*/
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)  {
    this->width=width;
    this->height=height;
    this->level=mode;
    ClearBoard();
    SetMine();
}
//funkcja składowa czyszcząca plansze ze wszystkich wartości
void MinesweeperBoard::ClearBoard() {

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            plansza[width][height].HasFlag=false;
            plansza[width][height].HasMine=false;
            plansza[width][height].isReveald=false;
        }
    }
}

void MinesweeperBoard::DebugDisplay() {
   for(int i=0;i<height;i++){
        for(int j=0;j<width;j++) {
            if(plansza[j][i].HasFlag){
                cout<<"[F";
            }
            else{
                cout<<"[.";
            }
            if(plansza[j][i].HasMine){
                cout<<"M";
            }
            else{
                cout<<".";
            }
            if(plansza[j][i].isReveald) {
                cout << "O]";
            }
            else{
                cout <<".]";
            }
        }
     cout<<endl;
    }

}

void MinesweeperBoard::SetMine() {
    srand(time(nullptr));
    int a,b;

    if(level==Easy) MNumber=0.2*width*height;

    if(level==Normal) MNumber=0.4*width*height;

    if(level==Hard) MNumber=0.6*width*height;
    for(int i=0;i<MNumber;i++){
        a=rand()% width;
        b=rand()% height;
        while(plansza[a][b].HasMine)
        {
            a=rand()% width;
            b=rand()% height;
        }

        plansza[a][b].HasMine=true;
    }

}

bool MinesweeperBoard::RevealdField(int row, int col) {


    if(FieldInfo(row,col)!=95)
        return false;

    plansza[col][row].isReveald=true;
        return true;
}

bool MinesweeperBoard::ToggleFlag(int row, int col) {


    if (FieldInfo(row, col) == 95) {

        plansza[col][row].HasFlag = true;
        return true;
    }

    if (FieldInfo(row, col) == 70) {
        plansza[col][row].HasFlag = false;
        return true;
    }

    return false;
}

void MinesweeperBoard::SetSize(GameMode Difficulty) {
    if(Difficulty==Easy){
        width=7;
        height=5;
    }
    if(Difficulty==Normal){
        width=10;
        height=8;
    }
    if(Difficulty==Hard){
        width=15;
        height=13;
    }
}

char MinesweeperBoard::countMines(int row, int col) const{
    char Counts=0;

  if(plansza[col][row-1].HasMine && row!=0) Counts++;// spr góre
  if(plansza[col][row+1].HasMine && row!=height) Counts++;//spr dół
  if(plansza[col-1][row].HasMine && col!=0) Counts++;//spr lewo
  if(plansza[col+1][row].HasMine && col!=width) Counts++;//spr prawo
  if(plansza[col-1][row-1].HasMine && (col!=0 && row!=0)) Counts++;//spr lewa góre
  if(plansza[col+1][row-1].HasMine && (col!=width && row!=0)) Counts++;//spr prawa góra
  if(plansza[col-1][row+1].HasMine && (col!=0 && row!=height ))Counts++;//spr lewy dół
  if(plansza[col+1][row+1].HasMine && (col!=width && row!=height)) Counts++;//spr prawy dół
    return Counts;
}

char MinesweeperBoard::FieldInfo(int row, int col) const{
    if(col>=this->width || col<0) return 35;

    if(row>=this->height || row <0) return 35;

    if(plansza[col][row].isReveald && plansza[col][row].HasMine){

        return 88;
    }
    if(plansza[col][row].isReveald && !plansza[col][row].HasMine){

        return 48+countMines(row,col);
    }
    if(plansza[col][row].HasFlag){

        return 70;
    }
    if(!plansza[col][row].isReveald && !plansza[col][row].HasFlag){
        return 95;
    }
    if(plansza[col][row].HasMine) return 77;


    abort();

}

STAN MinesweeperBoard::getGameState() const{

    int n=0;
    int freeFeild=width*height-MNumber;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++) {
            if(FieldInfo(i,j)==88) {

                return Lose;
            }
            if(plansza[j][i].isReveald && !plansza[j][i].HasMine) n++;
        }
    }

    if(n==freeFeild){

        return Win;
    }
    return Running;


}


int MinesweeperBoard::getwidth() const{
    return width;
}
int MinesweeperBoard::getheight() const{
    return height;
}
GameMode MinesweeperBoard::getLevel() {
    return level;
}









