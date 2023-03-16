//
// Created by sadow on 22.02.2023.
//

#include "GameManager.h"
#include <iostream>
#include <fstream>

using namespace std;

GameManager::GameManager(Board &board, Player &player) : b1(board), p1(player)
{

}

void GameManager::Play() {
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
    if(b1.getGameState()!=Running) cout<<"Nice you win or lost my game :)";

}

