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
		std::cout << "--opened a file: " << filename << std::endl;
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
	std::cout << raw.size() << std::endl;
	while (++i < raw.size())
	{
		if (!validate_characters(raw[i]))
			return (0);
	}
	return (1);
}

int raw_block::validate_characters(std::string str)
{
	unsigned int i = -1;
	while (str[++i])
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
	return (1);
}