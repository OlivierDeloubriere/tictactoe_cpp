#include <iostream>
#include "gameboard.h"

void swapPlayer(char &mark)
{
    if(mark=='X')
    {
        mark='O';
    }
    else
    {
        mark='X';
    }
};

int main()
{
    GameBoard board((int) 3);
    char playerMark = 'X';
    bool gameHasWinner=false;

    while (board.remainingTurns > 0 && !gameHasWinner)
    {
        int playerColumn;
        int playerRow;
        bool playerMarkIsPlacedWithSuccess;
        std::cout << "Player " << playerMark << "'s turn:" << std::endl;
        do
        {
            std::cout << "Row?";
            std::cin >> playerRow;
            std::cout << "Column?";
            std::cin >> playerColumn;
            playerMarkIsPlacedWithSuccess = board.AddPlayerMarkIfAvailable(playerRow, playerColumn, playerMark);
            if(!playerMarkIsPlacedWithSuccess)
            {
                std::cout << "Cannot place mark here!" << std::endl;
            }
        } while (!playerMarkIsPlacedWithSuccess);
        
        board.DrawBoard();
        
        gameHasWinner = board.PlayerHasWon(playerMark);
        if(gameHasWinner)
        {
            std::cout << "Player " << playerMark << " has won!!!!" << std::endl;
        }
        swapPlayer(playerMark);
    }

    if(board.remainingTurns==0 && !gameHasWinner)
    {
        std::cout << "It's a draw!!!" << std::endl;
    }

    return 0;
}