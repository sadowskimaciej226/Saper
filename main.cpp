#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameManager.h"
#include "SFMLGameMenu.h"
#include "SFML_Board.h"
#include "MSSFMLController.h"

using namespace std;


int main() {

    MinesweeperBoard board(5,5,Easy);
    MSSFMLView v(board);
    board.DebugDisplay();
    MSSFMLController ctrl(board,v);
    ctrl.play();

return 0;
}