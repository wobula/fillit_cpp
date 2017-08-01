#include <string>
#include <iostream>
#include <boost/format.hpp>
#include "raw_block.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

raw_block::raw_block()
{
	std::cout << "+raw block created" << std::endl;
}

raw_block::~raw_block()
{
	std::cout << "+raw block destroyed" << std::endl;
}

int raw_block::extract(char *filename)
{
	char buff[22];

	std::ifstream stream(filename);
	std::string buffer;
	if (stream.is_open())
	{
		std::cout << "--opened: " << filename << std::endl;
		while (stream.read(buff, 21))
		{
			buff[21] = '\0';
			raw.push_back(buff);
		}
		raw.push_back(buff);
		return (1);
	}
	return (0);
}

int raw_block::validate(void)
{
	unsigned int i = -1;
	std::cout << "--Block count: " << raw.size() << std::endl;
	while (++i < raw.size())
	{
		if (!validate_characters(raw[i], i))
			return (0);
		if (!validate_count(raw[i], i))
			return (0);
		if (!validate_tetrimino(raw[i], i))
			return (0);
	}
	std::cout << "-Validation complete!" << std::endl;
	return (1);
}

int raw_block::validate_characters(std::string str, int x)
{
	unsigned int i = -1;
	std::cout << "--Validating characters for block: " << x << std::endl;
	std::cout << str << std::endl;
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
		{
			std::cout << "Error: invalid character: " << str[i] << std::endl;
			return (0);
		}
	}
	return (1);
}

int raw_block::validate_count(std::string str, int x)
{
	unsigned int i = -1;
	int			 pound = 0;
	int 		 period = 0;
	int 		 newline = 0;
	std::cout << "--Validating count for block: " << x << std::endl;
	while (str[++i])
	{
		if (str[i] == '#')
			pound++;
		else if (str[i] == '.')
			period++;
		else if (str[i] == '\n')
			newline++;
	}
	if (pound == 4 && period == 12 && newline == 5)
	{
		std::cout << "--Validated: " << pound << period << newline << std::endl;
		return (1);
	}
	std::cout << "Error: invalid composition: " << pound << period << newline << std::endl;
	return (0);
}

int raw_block::validate_newline_pos(std::string str, int x)
{
	unsigned int i = -1;

	while (str[++i])
	{
		if (str[i] == '\n' && i % 5 != 0)
		{
			std::cout << "Error: invalid newline position" << std::endl;
			return (0);
		}
	}
	std::cout << "--Validated all newline positions for block " << x << std::endl;
	return (1);
}

int raw_block::validate_tetrimino(std::string str, int x)
{
	unsigned int i = -1;
	int 		 pound = 0;

	while (str[++i])
	{
		if (str[i] == '#')
		{
			pound++;
			if (str[i + 1] == '#')
				pound++;
			if (str[i + 2] == '#')
				pound++;
			if (str[i + 3] == '#')
				pound++;
			if (str[i + 4] == '#')
				pound++;
			if (str[i + 5] == '#')
				pound++;
			if (str[i + 6] == '#')
				pound++;
			if (str[i + 7] == '#')
				pound++;
			if (str[i + 9] == '#')
				pound++;
			if (str[i + 10] == '#')
				pound++;
			if (str[i + 11] == '#')
				pound++;
			if (str[i + 15] == '#')
				pound++;
			break ;
		}
	}
	std::cout << "Tetrimino count: " << pound << std::endl;
	if (pound == 4)
	{
		std::cout << "--Validated tetrimino composition for block " << x << std::endl;
		return (1);
	}
	std::cout << "--Error: invalid tetrimino composition for block " << x << std::endl;
	return (0);
}