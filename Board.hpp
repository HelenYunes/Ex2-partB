#include <string>
#include <unordered_map>
#include "Direction.hpp"

using namespace std;

struct EmptySpace
{
    char message = '_';
};

namespace ariel
{
    class Board
    {
        uint min_row;
        uint max_row;
        uint min_column;
        uint max_column;
        char message = '_';
        unordered_map<uint, unordered_map<uint, EmptySpace>> board;

    public:
        Board()
        {
            max_row = 0;
            max_column = 0;
            min_row = UINT32_MAX;
            min_column = UINT32_MAX;
        }
        ~Board() {}
        void post(uint row, uint column, Direction direction, string message);
        std::string read(uint row, uint column, Direction direction, uint length);
        void show();
    };
}