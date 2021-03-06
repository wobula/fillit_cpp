#ifndef RAW_BLOCK_HPP
# define RAW_BLOCK_HPP
# include <string>
# include <iostream>
# include <vector>
# include <fstream>

class raw_block
{
	public:
		raw_block();
		~raw_block();
		int extract(char *filename);
		int validate(void);
		int validate_characters(std::string str, int i);
		int validate_count(std::string str, int x);
		int validate_newline_pos(std::string str, int x);
		int validate_tetrimino(std::string str, int x);
		std::vector<std::string> getVector();
	private:
		std::vector<std::string> raw;
};

#endif