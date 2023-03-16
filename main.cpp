#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameManager.h"
#include "SFMLGameMenu.h"
#include "SFML_Board.h"

using namespace std;


int main() {
    SFMLGameMenu menu;

    Board board(menu);
    cout<<board.ToggleFlag(6,4)<<endl;
    board.RevealdField(0,0);
   cout<<board.FieldInfo(0,0)<<endl;
    cout<<board.getGameState();
    SFML_Board Game(board,menu);
    Game.DrawBoard();

return 0;
}