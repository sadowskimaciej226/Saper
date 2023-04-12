#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameManager.h"
#include "SFMLGameMenu.h"
#include "SFML_Board.h"

using namespace std;


int main() {
    SFMLGameMenu menu;


    //MinesweeperBoard board(menu);
    MinesweeperBoard board(7,5,Easy);


   cout<<board.RevealdField(0,0)<<endl;
    cout<<board.RevealdField(1,2)<<endl;
    cout<<board.RevealdField(2,5)<<endl;
    cout<<board.ToggleFlag(1,1);

   // board.RevealdField(2,1);
   // board.RevealdField(3,1);
   //cout<<board.FieldInfo(0,0)<<endl;

   //  cout<<board.getGameState();
    MSSFMLView Game(board,menu);
    board.DebugDisplay();
    Game.View();

return 0;
}