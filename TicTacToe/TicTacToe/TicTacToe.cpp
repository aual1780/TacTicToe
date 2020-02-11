#include <iostream>
#include <vector>

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

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


    DisplayBoard(board, rows, cols);


    std::string discard;
    std::cin >> discard;

    return 0;
}



