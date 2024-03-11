#include "../gameboard.h"
#include <iostream>

int main()
{
    GameBoard board(3);

    board.AddPlayerMarkIfAvailable(2,1,'X');
    board.AddPlayerMarkIfAvailable(2,2,'X');
    board.AddPlayerMarkIfAvailable(2,3,'X');

    std::cout << board.PlayerHasWon('X') << std::endl;

    board = GameBoard(3);

    board.AddPlayerMarkIfAvailable(1,1,'X');
    board.AddPlayerMarkIfAvailable(2,2,'X');
    board.AddPlayerMarkIfAvailable(3,3,'X');
    std::cout << board.PlayerHasWon('X') << std::endl;

    return 0;
}