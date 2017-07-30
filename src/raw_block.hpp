#ifndef RAW_BLOCK_HPP
#define RAW_BLOCK_HPP
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class raw_block
{
	public:
		raw_block();
		~raw_block();
		int extract(char *filename);
		int validate();
		int valid_characters(std::string str);
	private:
		std::vector<std::string> raw;
};

#endif