#include <iostream>
#include <math.h>
#include <cstring>
#include "val_block.hpp"
#include <stdlib.h>

val_block::val_block(raw_block &test) : valid(&test),
										current_block(0),
										letter('A'),
										total_blocks(valid->getVector().size())
{
	std::cout << "+val block created" << std::endl;
	convert_to_xy();
	std::cout << total_blocks << std::endl;
	min_board_size = 4;
	empty_board();
	getBoard();
	std::cout << "-Recursion started" << std::endl;
	while (!recurse(board))
		increaseMapSize();
	getBoard();
}

val_block::~val_block()
{
	delete coords;
	std::cout << "+val block destroyed" << std::endl;
}

int	 val_block::recurse(std::vector<std::string> board)
{
	unsigned int row = -1;
	unsigned int col = -1;
	while (++row < board.size() && current_block < total_blocks)
	{
		col = -1;
		while (++col < board[row].size() && current_block < total_blocks)
		{
			if (board[row][col] == '.')
			{
				if (putBlock(row, col, coords[current_block]))
					break ;
			}
		}
	}
	std::cout << "current block: " << current_block << "total blocks: " << total_blocks << std::endl;
	if (current_block == total_blocks)
		return (1);
	std::cout << "--No solution found with board size: " << min_board_size << std::endl;
	return (0);
}

int  val_block::putBlock(unsigned int row, unsigned int col, int* coords)
{
	std::cout << "-Trying to putblock1: " << coords[0] + col << coords[1] + row << std::endl;
	if (coords[1] + row < min_board_size && coords[0] + col < min_board_size && board[coords[1] + row][coords[0] + col] == '.')
	{
		std::cout << "-Trying to putblock2: " << coords[2] + col  << coords[3] + row << std::endl;
		if (coords[3] + row < min_board_size && coords[2] + col < min_board_size && board[coords[3] + row][coords[2] + col] == '.')
		{
			std::cout << "-Trying to putblock3: " << coords[4] + col << coords[5] + row << std::endl;
			if (coords[5] + row < min_board_size && coords[4] + col < min_board_size && board[coords[5] + row][coords[4] + col] == '.')
			{
				std::cout << "-Trying to putblock4: " << coords[6] + col << coords[7] + row << std::endl;
				if (coords[7] + row < min_board_size && coords[6] + col < min_board_size && board[coords[7] + row][coords[6] + col] == '.')
				{
					std::cout << "--Piece fits: " << current_block << " -> " << letter << std::endl;
					board[coords[1] + row][coords[0] + col] = letter;
					board[coords[3] + row][coords[2] + col] = letter;
					board[coords[5] + row][coords[4] + col] = letter;
					board[coords[7] + row][coords[6] + col] = letter;
					letter++;
					current_block++;
					getBoard();
					std::cout << "--trying next letter: " << letter << std::endl;
					if (!recurse(board))
					{
						remove_piece(letter);
						return (0);
					}
					return (1);
				}
			}
		}
	}
	std::cout << "--putblock failed" << std::endl;
	return (0);
}

void val_block::remove_piece(char remove_letter)
{
	unsigned int row = -1;
	unsigned int col = -1;
	int count = 0;
	letter--;
	current_block--;
	std::cout << "-Removing piece" << std::endl;
	while (++row < board.size() && current_block < total_blocks)
	{
		col = -1;
		while (++col < board[row].size() && current_block < total_blocks)
		{
			if (board[row][col] == remove_letter)
			{
				board[row][col] = '.';
				count++;
				if (count == 4)
				{
					std::cout << "--Piece removed!" << std::endl;
					return ;
				}
			}
		}
	}
}

void val_block::increaseMapSize(void)
{
	current_block = 0;
	letter = 'A';
	min_board_size++;
	board.clear();
	empty_board();
}

void val_block::getBoard(void)
{
	std::vector<std::string>::iterator row = board.begin() - 1;
	while (++row != board.end())
		std::cout << *row << std::endl;
}

int val_block::convert_to_xy(void)
{
	unsigned int i = -1;
	coords = new int*[valid->getVector().size()];
	std::cout << "-Conversion started" << std::endl;
	std::cout << "--Block count: " << valid->getVector().size() << std::endl;
	while (++i < valid->getVector().size())
	{
		coords[i] = new int[8];
		extract_cords((valid->getVector())[i], i);
	}
	std::cout << "--Conversion complete!" << std::endl;
	return (1);
}

void val_block::extract_cords(std::string str, unsigned int i)
{
	int x = -1;
	int y = -1;

	std::cout << "-Extracting coords for piece: " << i << std::endl;
	while (str[++x])
	{
		if (str[x] == '#')
		{
			coords[i][++y] = 0;
			coords[i][++y] = 0;
			if (str[x + 1] == '#')
			{
				coords[i][++y] = 1;
				coords[i][++y] = 0;
			}
			if (str[x + 2] == '#')
			{
				coords[i][++y] = 2;
				coords[i][++y] = 0;
			}
			if (str[x + 3] == '#')
			{
				coords[i][++y] = 3;
				coords[i][++y] = 0;
			}
			if (str[x + 4] == '#')
			{
				coords[i][++y] = 4;
				coords[i][++y] = 0;
			}
			if (str[x + 5] == '#')
			{
				coords[i][++y] = 0;
				coords[i][++y] = 1;
			}
			if (str[x + 6] == '#')
			{
				coords[i][++y] = 1;
				coords[i][++y] = 1;
			}
			if (str[x + 7] == '#')
			{
				coords[i][++y] = 2;
				coords[i][++y] = 1;
			}
			if (str[x + 9] == '#')
			{
				coords[i][++y] = -1;
				coords[i][++y] = 2;
			}
			if (str[x + 10] == '#')
			{
				coords[i][++y] = 0;
				coords[i][++y] = 2;
			}
			if (str[x + 11] == '#')
			{
				coords[i][++y] = 1;
				coords[i][++y] = 2;
			}
			if (str[x + 15] == '#')
			{
				coords[i][++y] = 0;
				coords[i][++y] = 3;
			}
			std::cout << str << std::endl;
			std::cout << coords[i][0] << coords[i][1] << std::endl;
			std::cout << coords[i][2] << coords[i][3] << std::endl;
			std::cout << coords[i][4] << coords[i][5] << std::endl;
			std::cout << coords[i][6] << coords[i][7] << std::endl;
			return ;
		}
	}
}

void val_block::find_smallest_map(int block_count)
{
	int size;

	std::cout << "-Finding smallest map" << std::endl;
	while (!(size = sqrt(block_count)))
		block_count++;
	std::cout << "--Your minimum board size is: " << size << std::endl;
	min_board_size = size;
}

void val_block::empty_board()
{
	unsigned int x = -1;
	char	*ptr;

	std::cout << "-Creating empty board" << std::endl;
	ptr = (char*)malloc(sizeof(char) * (min_board_size + 1));
	ptr[min_board_size] = '\0';
	while (++x < min_board_size)
		ptr[x] = '.';
	std::string tmp = ptr;
	x = -1;
	while (++x < min_board_size)
		board.push_back(tmp);
	free(ptr);
	ptr = NULL;
	std::cout << "--Board created!" << std::endl;
}