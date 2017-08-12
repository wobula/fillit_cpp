#ifndef VAL_BLOCK_HPP
# define VAL_BLOCK_HPP
# include <string>
# include <iostream>
# include <vector>
# include <fstream>
# include <cstring>
# include "raw_block.hpp"

class val_block
{
	public:
						val_block(raw_block &test);
						~val_block();
		int 			convert_to_xy(void);
		void 			extract_cords(std::string str);
		void 			find_smallest_map(int block_count);
		void 			empty_board();
		void 			getBoard();
		int	 			recurse(std::vector<std::string> board);
		void			increaseMapSize(void);
		int  			putBlock(unsigned int row, unsigned int col, int* coords);
		void 			remove_piece(char remove_letter);
		void 			ft_cplus1(std::string str, int x);
	private:
		raw_block* 		valid;
		int 	  		current_block;
		char 	  		letter;
		int** 	  		coords;
		unsigned int	min_board_size;
		int 	  		total_blocks;
		std::vector<std::string> board;
};

#endif