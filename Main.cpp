
#include "Direction.hpp"
#include "Board.hpp"
#include <iostream>

using namespace std;
using ariel::Direction;

/**
 * an array of colors 
 */
const string colors[] =
    {"\x1B[0m", "\x1B[31m", "\x1B[32m", "\x1B[33m", "\x1B[34m", "\x1B[35m", "\x1B[36m", "\x1B[37m"};
int main()
{
    ariel::Board board;
    char option;
    string message;
    uint row, column, direction, length;
    int flag = 1;
    while (flag)
    {
        cout << colors[rand() % 7];
        board.show();
        cout << "Welcome, you're on the bulletin board! \n"
                "Please enter P to post on the board or R to read from the board: ";
        cin >> option;
        switch (option)
        {
        case 'P':
        {
            cout << "\nPlease enter a row: ";
            cin >> row;
            cout << "\nPlease enter a column: ";
            cin >> column;
            cout << "\nPlease enter 0 for horizontal direction or 1 for vertical direction: ";
            cin >> direction;
            cout << "\nPlease enter your message: " << endl;
            cin >> message;
            if (direction == 0)
            {
                board.post(row, column, Direction::Horizontal, message);
            }
            if (direction == 1)
            {
                board.post(row, column, Direction::Vertical, message);
            }
            break;
        }
        case 'R':
        {
            cout << "\nPlease enter a row: ";
            cin >> row;
            cout << "\nPlease enter a column: ";
            cin >> column;
            cout << "\nPlease enter 0 for horizontal direction or 1 for vertical direction: ";
            cin >> direction;
            cout << "\nPlease enter the length of the message: ";
            cin >> length;
            if (direction == 0)
            {
                cout << colors[rand() % 7];
                cout << board.read(row, column, Direction::Horizontal, length) << endl;
            }
            if (direction == 1)
            {
                cout << colors[rand() % 7];
                cout << board.read(row, column, Direction::Vertical, length) << endl;
            }

            break;
        }
        default:
        {
            cout << "Goodbye :) \n";
            flag = 0;
        }
        }
    }
}