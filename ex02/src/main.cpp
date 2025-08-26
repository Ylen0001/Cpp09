#include "../includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try{
		if(argc <= 2)
		{
			std::cerr << "Error : Wrong number of arguments!" << std::endl;
			return 1;
		}
	PmergeMe test(argc, argv);
	test.run();

	}catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return (0);
}
