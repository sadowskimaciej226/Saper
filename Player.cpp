//
// Created by sadow on 22.02.2023.
//

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(MinesweeperBoard &board) : b(board)
{

}

void Player::RevealField() {
    int row, field;
    bool rv;

    do {

        cout << "To reveal field please select a row: ";
        cin >> row;
        cout << endl;
        cout << "Please select which field in " << row << " row: ";
        cin >> field;
        rv=b.RevealdField(field,row);
    }while(not rv);


}

void Player::ToggleFlag() {
    int row, field;
    bool rv;

    do {

        cout << "To toggle flag please select a row: ";
        cin >> row;
        cout << endl;
        cout << "Please select which field in " << row << " row: ";
        cin >> field;
        rv=b.ToggleFlag(field,row);
    }while(not rv);

}
