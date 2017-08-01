#ifndef VAL_BLOCK_HPP
# define VAL_BLOCK_HPP
# include <string>
# include <iostream>
# include <vector>
# include <fstream>
# include "raw_block.hpp"

class val_block
{
	public:
		val_block(raw_block &test);
		~val_block();
	private:
		raw_block *valid;
};

#endif