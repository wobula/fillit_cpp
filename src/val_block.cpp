#include <iostream>
#include "val_block.hpp"

val_block::val_block(raw_block &test) : valid(&test)
{
	std::cout << "+val block created" << std::endl;
}

val_block::~val_block()
{
	std::cout << "+val block destroyed" << std::endl;
}