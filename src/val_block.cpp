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
	find_smallest_map(valid->getVector().size());
	empty_board();
	getBoard();
}

val_block::~val_block()
{
	delete coords;
	std::cout << "+val block destroyed" << std::endl;
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
	std::cout << "-Conversion complete!" << std::endl;
	return (1);
}

void val_block::extract_cords(std::string str, unsigned int i)
{
	int x = -1;
	int y = -1;

	std::cout << "inside extract cords" << std::endl;
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
	int x = -1;
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