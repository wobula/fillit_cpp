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
	char buff[21];

	std::ifstream stream(filename);
	if (stream.is_open())
	{
		std::cout << "--opened a file: " << filename << std::endl;
		while (stream.read(buff, 21))
			raw.push_back(buff);
		raw.push_back(buff);
		return (1);
	}
	return (0);
}

int raw_block::validate()
{
	unsigned int i = -1;
	std::cout << raw.size() << std::endl;
	while (++i < raw.size())
	{
		std::cout << raw[i] << std::endl;
	}
	return (1);
}

int raw_block::valid_characters(std::string str)
{
	unsigned int i = -1;
	char 		 c = 0;
	while (++i <= str.size() && (c = str[i]))
	{
		if (c != '\n' && c != '.' && c != '#')
		{
			std::cout << "Error: invalid symbol: " << c << std::endl;
			return (0);
		}
	}
	std::cout << "--characters validated" << std::endl;
	return (1);
}