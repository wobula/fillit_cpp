#ifndef RAW_BLOCK_HPP
#define RAW_BLOCK_HPP
#include <string>

class raw_block
{
	public:
		raw_block();
		~raw_block();
		int validate(char *filename);
	private:
		std::string raw_data;
};

#endif