#include <iostream>
#include <vector>

enum class BoardCell
{
    Empty,
    X,
    O,
};

int main()
{
    auto board = CreateBoard(3, 3);

    return 0;
}



std::vector<std::vector<BoardCell>> CreateBoard(int rows, int cols)
{
    auto arr = std::vector<std::vector<BoardCell>>(rows, std::vector<BoardCell>(cols, BoardCell::Empty));

    return arr;
}