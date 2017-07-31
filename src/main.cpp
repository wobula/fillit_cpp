#include <iostream>
#include <string>
#include "raw_block.hpp"

int parse_args(int argc, char **argv)
{
	int ret = 0;

	(void)argv;
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

	if (parse_args(argc, argv))
	{
		std::cout << "-Validating blocks" << std::endl;
		test.extract(argv[1]);
		test.validate();
	}
	return (0);
}