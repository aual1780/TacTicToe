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

std::string DisplayBoard(std::vector<std::vector<BoardCell>> board)
{
    std::string result = "";
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            enum BoardCell spot = board[r][c];
            if(spot == BoardCell::Empty)
            {
                result += "   ";
            }
            if(spot == BoardCell::X)
            {
                result += " X ";
            }
            else if(spot == BoardCell::O)
            {
                result += " O ";
            }
        }
        result += "\n";
    }
    return result;
}