#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class BoardCell
{
    Empty,
    X,
    O,
};
std::string CellToString(const BoardCell& cell)
{
    switch (cell)
    {
    case BoardCell::Empty:
        return "_";
    case BoardCell::X:
        return "X";
    case BoardCell::O:
        return "O";
    default:
        return "_";
    }
}


std::vector<std::vector<BoardCell>> CreateBoard(int rows, int cols)
{
    auto arr = std::vector<std::vector<BoardCell>>(rows, std::vector<BoardCell>(cols, BoardCell::Empty));
    return arr;
}


void PlaceMarker(std::vector<std::vector<BoardCell>>& board, const int& row, const int& col, const BoardCell& cell)
{
    auto str = CellToString(cell);
    if (str == "_")
    {
        throw std::runtime_error("Invalid token");
    }

    board[row][col] = cell;
}


void DisplayBoard(std::vector<std::vector<BoardCell>> arr, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            std::cout << CellToString(arr[r][c]);

            if (c < cols - 1)
            {
                std::cout << "|";
            }
        }

        if (r < rows - 1)
        {
            std::cout << std::endl;
        }
    }
}


int main()
{
    int rows = 3;
    int cols = 3;
    auto board = CreateBoard(rows, cols);

    PlaceMarker(board, 0, 0, BoardCell::X);

    DisplayBoard(board, rows, cols);


    std::string discard;
    std::cin >> discard;

    return 0;
}



