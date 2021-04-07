#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    void Board::post(uint row, uint column, Direction direction, string message)
    {
        min_row = min(min_row, row);
        min_column= min(min_column, column);
 
        for (uint i = 0; i < message.length(); ++i)
        {
            board[row][column].message = message.at(i);
            if (direction == Direction::Horizontal)
            {
                column++;
            }
            else
            {
                row++;
            }
        }
        max_row = max(max_row, row);
        max_column = max(max_column, column);
    }

    string Board::read(uint row, uint column, Direction direction, uint length)
    {
        string output;
        for (uint i = 0; i < length; i++)
        {
            output +=  board[row][column].message;
            if (direction == Direction::Horizontal)
            {
                column++;
            }
            else
            {
                row++;
            }
        }
        return output;
    }

    void Board::show()
    {
        for (uint Row = min_row; Row <= max_row; Row++)
        {
            for (uint Column = min_column; Column <= max_column; Column++)
            {
                cout << board[Row][Column].message << " ";
            }
            cout << "\n";
        }
    }
}
