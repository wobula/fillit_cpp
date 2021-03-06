#include <iostream>
#include <string>
#include "raw_block.hpp"
#include "val_block.hpp"

int parse_args(int argc)
{
	int ret = 0;

	std::cout << "-Parsing arguments:" << std::endl;
	if (argc  == 2 && (ret = 1))
		std::cout << "--Correct number of args" << std::endl;
	else
		std::cout << "--Incorrect number of args: " << argc << std::endl;
	return (ret);
}

int	main(int argc, char **argv)
{
	raw_block test;

	if (parse_args(argc))
	{
		std::cout << "-Validating blocks" << std::endl;
		test.extract(argv[1]);
		if (test.validate())
			val_block solve(test);
	}
	return (0);
}