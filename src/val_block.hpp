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
		void 			extract_cords(std::string str, unsigned int block_index);
		void 			find_smallest_map(int block_count);
		void 			empty_board();
		void 			getBoard();
		int	 			recurse(std::vector<std::string> board);
		void			increaseMapSize(void);
		int  			putBlock(unsigned int row, unsigned int col, int* coords);
		void 			remove_piece(char remove_letter);
		void 			ft_cplus1(std::string str, int x, unsigned int block_index);
		void 			ft_cplus1plus2(std::string str, int x, unsigned int block_index);
		void 			ft_cplus1plus5(std::string str, int x, unsigned int block_index);
		void 			ft_cplus1plus5extra(std::string str, int x, unsigned int block_index);
		void 			ft_cplus1plus6(std::string str, int x, unsigned int block_index);
		void 			ft_cplus1plus6plus2or11(std::string str, int x, unsigned int block_index);
		void 			ft_cplus1plus6plus5or7(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5plus6(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5plus4(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5plus4plus6or9(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5plus10(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5plus10plus6or15(std::string str, int x, unsigned int block_index);
		void 			ft_cplus5plus10plus9or11(std::string str, int x, unsigned int block_index);
	private:
		raw_block* 		valid;
		int 	  		current_block;
		char 	  		letter;
		int** 	  		cord;
		unsigned int	min_board_size;
		int 	  		total_blocks;
		std::vector<std::string> board;
};

#endif