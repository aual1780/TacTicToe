#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class BoardCell
{
	Empty = 0,
	X = 1,
	O = 3,
};

inline void operator^=(BoardCell& a, const int& b)
{
	a = static_cast<BoardCell>(static_cast<int>(a) ^ b);
}

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

void GetPlayerChoice(std::vector<std::vector<BoardCell>> arr, int& row, int& col)
{
	do
	{
		do
		{
			std::cout << "Please select the row you would like to play in (1-3)" << std::endl;
			std::cin >> row;
			row -= 1;
		} while (row > 2 || row < 0);

		do {
			std::cout << "Please select the column you would like to play in (1-3)" << std::endl;
			std::cin >> col;
			col -= 1;
		} while (col > 2 || col < 0);

		if (arr[row][col] == BoardCell::Empty)
		{
			return;
		}
		else
		{
			std::cout << "Invalid Cell Selection" << std::endl;
		}

	} while (true);
}

int main()
{
	BoardCell currentGlyph = BoardCell::X;
	int rows = 3;
	int cols = 3;
	auto board = CreateBoard(rows, cols);

	std::cout << "TIC TAC TOE" << std::endl;

	DisplayBoard(board, rows, cols);
	std::cout << std::endl;


	for (int i = 0; i < rows * cols; i++)
	{
		std::cout << "Current Player: " << CellToString(currentGlyph);
		std::cout << std::endl;

		int row = -1;
		int col = -1;
		GetPlayerChoice(board, row, col);

		PlaceMarker(board, row, col, currentGlyph);
		currentGlyph ^= 2;

		DisplayBoard(board, rows, cols);
		std::cout << std::endl;
	}


	std::cout << "GAME OVER" << std::endl;
	std::string discard;
	std::cin >> discard;
	return 0;
}



