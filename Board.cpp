#include "Board.h"
#include <iostream>
using namespace std;

MinesweeperBoard::MinesweeperBoard(SFMLGameMenu & m1) : menu(m1)
{

    level=m1.menu();
    if(level==Debug) abort();
    SetSize(level);
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

    if(level==Easy) MNumber=5;

    if(level==Normal) MNumber=20;

    if(level==Hard) MNumber=80;
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

    plansza[row][col].isReveald=true;
        return true;
}

bool MinesweeperBoard::ToggleFlag(int row, int col) {


  if(FieldInfo(row,col)!=95)
      return false;

    plansza[row][col].HasFlag=true;
    return true;
}

void MinesweeperBoard::SetSize(LEVEL HowHard) {
    if(HowHard==Easy){
        width=7;
        height=5;
    }
    if(HowHard==Normal){
        width=10;
        height=8;
    }
    if(HowHard==Hard){
        width=15;
        height=13;
    }
}

char MinesweeperBoard::countMines(int row, int col) const{
    char Counts=0;
    if(plansza[row-1][col].HasMine && row!=0){ //w lewo
        Counts++;
    }
    if(plansza[row+1][col].HasMine && row!=width){//w prawo
        Counts++;
    }
    if(plansza[row][col-1].HasMine && col!=0){//w dół
        Counts++;
    }
    if(plansza[row][col+1].HasMine && col!=height){//w góre
        Counts++;
    }
    if(plansza[row-1][col-1].HasMine && (row!=0 || col!=0)){//lewy dół
        Counts++;
    }
    if(plansza[row-1][col+1].HasMine && (row!=0 || col!=height)){//lewa góra
        Counts++;
    }
    if(plansza[row+1][col+1].HasMine && (row!=width || col!=height)){//prawa góra
        Counts++;
    }
    if(plansza[row+1][col-1].HasMine && (row!=width || col!=0)){//prawy dół
        Counts++;
    }
    return Counts;
}

char MinesweeperBoard::FieldInfo(int row, int col) const{
    if(row>=this->width || row<0) return 35;

    if(col>=this->height || col <0) return 35;

    if(plansza[row][col].isReveald && plansza[row][col].HasMine){

        return 88;
    }
    if(plansza[row][col].isReveald && !plansza[row][col].HasMine){

        return 48+countMines(row,col);
    }
    if(plansza[row][col].HasFlag){

        return 70;
    }
    if(!plansza[row][col].isReveald && !plansza[row][col].HasFlag){
        return 95;
    }
    if(plansza[row][col].HasMine) return 77;


    abort();

}

STAN MinesweeperBoard::getGameState() const{

    int n=0;
    int freeFeild=width*height-MNumber;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++) {
            if(FieldInfo(j,i)==88) return Lose;
            if(FieldInfo(j,i)>=48 || FieldInfo(j,i)<=57) n++;
        }
    }
    if(n==freeFeild) return Win;
    return Running;

}


int MinesweeperBoard::getwidth() const{
    return width;
}
int MinesweeperBoard::getheight() const{
    return height;
}
LEVEL MinesweeperBoard::getLevel() {
    return level;
}





