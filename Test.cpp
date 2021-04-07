#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Horizontal reading test")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 10, Direction::Horizontal, "abcdef"));
    CHECK(board.read(0, 10, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 10, Direction::Vertical, 0) == "");
    CHECK(board.read(0, 10, Direction::Horizontal, 1) == "a");
    CHECK(board.read(0, 10, Direction::Horizontal, 2) == "ab");
    CHECK(board.read(0, 10, Direction::Horizontal, 3) == "abc");
    CHECK(board.read(0, 10, Direction::Horizontal, 4) == "abcd");
    CHECK(board.read(0, 10, Direction::Horizontal, 5) == "abcde");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "abcdef");
    CHECK(board.read(0, 11, Direction::Horizontal, 1) == "b");
    CHECK(board.read(0, 12, Direction::Horizontal, 1) == "c");
    CHECK(board.read(0, 13, Direction::Horizontal, 1) == "d");
    CHECK(board.read(0, 14, Direction::Horizontal, 1) == "e");
    CHECK(board.read(0, 15, Direction::Horizontal, 1) == "f");
    CHECK(board.read(0, 16, Direction::Horizontal, 1) == "_");
}

TEST_CASE("Vertical reading test")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 10, Direction::Vertical, "abcdef"));
    CHECK(board.read(0, 10, Direction::Vertical, 0) == "");
    CHECK(board.read(0, 10, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 10, Direction::Vertical, 1) == "a");
    CHECK(board.read(0, 10, Direction::Vertical, 2) == "ab");
    CHECK(board.read(0, 10, Direction::Vertical, 3) == "abc");
    CHECK(board.read(0, 10, Direction::Vertical, 4) == "abcd");
    CHECK(board.read(0, 10, Direction::Vertical, 5) == "abcde");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "abcdef");
    CHECK(board.read(1, 10, Direction::Vertical, 1) == "b");
    CHECK(board.read(2, 10, Direction::Vertical, 1) == "c");
    CHECK(board.read(3, 10, Direction::Vertical, 1) == "d");
    CHECK(board.read(4, 10, Direction::Vertical, 1) == "e");
    CHECK(board.read(5, 10, Direction::Vertical, 1) == "f");
    CHECK(board.read(6, 10, Direction::Vertical, 1) == "_");
}
TEST_CASE("Horizontal override test")
{
    Board board;
    board.post(0, 10, Direction::Horizontal, "abcdef");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "abcdef");
    board.post(0, 10, Direction::Horizontal, "www");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "wwwdef");
    board.post(0, 11, Direction::Horizontal, "x");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "wxwdef");
    board.post(0, 12, Direction::Horizontal, "y");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "wxydef");
    board.post(0, 13, Direction::Horizontal, "z");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "wxyzef");
    board.post(0, 14, Direction::Horizontal, "!");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "wxyz!f");
    board.post(0, 15, Direction::Horizontal, "!");
    CHECK(board.read(0, 10, Direction::Horizontal, 6) == "wxyz!!");
}

TEST_CASE("Vertical override test")
{
    Board board;
    board.post(0, 10, Direction::Vertical, "abcdef");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "abcdef");
    board.post(0, 10, Direction::Vertical, "www");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "wwwdef");
    board.post(1, 10, Direction::Vertical, "x");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "wxwdef");
    board.post(2, 10, Direction::Vertical, "y");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "wxydef");
    board.post(3, 10, Direction::Vertical, "z");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "wxyzef");
    board.post(4, 10, Direction::Vertical, "!");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "wxyz!f");
    board.post(5, 10, Direction::Vertical, "!");
    CHECK(board.read(0, 10, Direction::Vertical, 6) == "wxyz!!");
}

TEST_CASE("Horizontal random message check")
{
    Board board;
    int message_length;
    char random_char;
    string random_message;

    for (int i = 0; i < 20; i++)
    {
        random_message = "";
        message_length = rand() % 5;
        for (int i = 0; i < message_length; i++)
        {
            random_char = (rand() % 95) + 32;
            random_message += random_char;
        }

        CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, random_message));
        CHECK(board.read(0, 0, Direction::Horizontal, random_message.size()) == random_message);
    }
}

TEST_CASE("Vertical random message test")
{
    Board board;
    int message_length;
    char random_char;
    string random_message;

    for (int i = 0; i < 20; i++)
    {
        random_message = "";
        message_length = rand() % 5;
        for (int i = 0; i < message_length; i++)
        {
            random_char = (rand() % 95) + 32;
            random_message += random_char;
        }
        // cout<<random_message<<endl;

        CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, random_message));
        CHECK(board.read(0, 0, Direction::Vertical, random_message.size()) == random_message);
    }
}
