#include "gameboard.h"


GameBoard::GameBoard(int numberOfRowsAndColumns) : numRows(numberOfRowsAndColumns), numCols(numberOfRowsAndColumns)
{
    std::vector<char> boardRow;
    //initialisation of the board
    for (int colIndex = 0; colIndex<numCols; colIndex++)
    {
        boardRow.push_back(' ');
    }
    for (int rowIndex = 0; rowIndex<numRows; rowIndex++)
    {
        board.push_back(boardRow);
    }
    remainingTurns = numRows * numCols;
};

void GameBoard::DrawBoard() {
    using namespace std;
    string lineToDraw;
    for (int rowIndex = 0; rowIndex<numRows; rowIndex++)
    {
        lineToDraw = "";
        for (int colIndex = 0; colIndex<numCols; colIndex++)
        {
            if (colIndex > 0 && colIndex < numCols) 
            {
                lineToDraw += "|";
            }
            lineToDraw += board[rowIndex][colIndex];
        }
        cout << lineToDraw << endl;
    };
    cout << endl;
};

bool GameBoard::AddPlayerMarkIfAvailable(int rowNumber, int colNumber, char playerMark)
{
    if(rowNumber > numRows || colNumber > numCols)
    {
        return false;
    }
    if(board[rowNumber-1][colNumber-1] ==' ')
    {
        board[rowNumber-1][colNumber-1] = playerMark;
        remainingTurns -= 1;
        return true;
    } else
    {
        return false;
    }
    
};

bool GameBoard::PlayerHasWon(char playerMark)
{
    bool result=false;
    //check rows
    for (int i=0;i<numRows;i++)
    {
        for(int j=0; j<numCols; j++)
        {
            if(j==0)
            {
                result = (board[i][j] == playerMark);
            }
            else
            {
                result = result && (board[i][j] == playerMark);
            }
        }
        if(result) {return result;};
    }
    //check columns
    for (int j=0; j<numCols; j++)
    {
        for (int i=0;i<numRows;i++)
        {
            if(i==0)
            {
                result = (board[i][j] == playerMark);
            }
            else
            {
                result = result && (board[i][j] == playerMark);
            }
        }
        if(result) {return result;};
    }
    //check diagonal
    for (int i=0;i<numRows;i++)
        {
            if(i==0)
            {
                result = (board[i][i] == playerMark);
            }
            else
            {
                result = result && (board[i][i] == playerMark);
            }
        }
    if(result) {return result;};
    return result;
};