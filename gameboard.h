#include <iostream>
#include <vector>

class GameBoard
{
    private:
        std::vector<std::vector<char>> board;
        int numRows;
        int numCols;

    public:
        int remainingTurns;
        GameBoard(int numberOfRowsAndColumns);
        void DrawBoard();
        bool AddPlayerMarkIfAvailable(int rowNumber, int colNumber, char playerMark);
        bool PlayerHasWon(char playerMark);
};