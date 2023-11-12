#include "hello-greet.h"
#include <ctime>
#include <string>
#include <iostream>

void print_localtime()
{
	std::time_t result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result));
}

int main(int argc, char **argv)
{
	std::string who = "wolrd";
	if (argc > 1)
	{
		who = argv[1];
	}
	std::cout << get_greet(who) << std::endl;
	print_localtime();
	return 0;
}