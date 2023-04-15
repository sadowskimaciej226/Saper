//
// Created by sadow on 22.02.2023.
//

#include "GameManager.h"
#include <iostream>
#include <fstream>

using namespace std;

MSTextController::MSTextController(MinesweeperBoard &board, Player &player) : b1(board), p1(player)
{

}

void MSTextController::Play() {
    int n;
    b1.DebugDisplay();
    cout<<endl;
    while(b1.getGameState()==Running)
    {
        do {
            cout << "Press 1 to toggle Flag.\nPress 2 to reveal field\n";
            cin >> n;
        } while (n != 1 && n != 2);
        if (n == 1) p1.ToggleFlag();
        if (n == 2) p1.RevealField();
        b1.DebugDisplay();
    }


}

void MSTextController::Board_view() {

    for(int i=0;i<b1.getheight();i++){
        for(int j=0;j<b1.getwidth();j++) {
            if(b1.FieldInfo(j,i)==70){
                cout<<"[F";
            }
            else{
                cout<<"[";
            }
            if(b1.FieldInfo(j,i)==88){
                cout<<"X";
            }
            else{
                cout<<".";
            }
            if(b1.FieldInfo(j,i)>=48&&b1.FieldInfo(j,i)<=56) {
                cout << b1.FieldInfo(j,i);
            }
            else{
                cout <<"]";
            }
        }
        cout<<endl;
    }
}

