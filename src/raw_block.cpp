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

int raw_block::validate(char *filename)
{
	std::string line;
	std::ifstream stream(filename);
	if (stream.is_open())
	{
		std::cout << "opened a file!" << std::endl;
		while (getline(stream, line))
		{
			std::cout << line << std::endl;
		}
	}
	return (1);
}