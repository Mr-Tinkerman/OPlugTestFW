#include <iostream>
#include <vector>

#include "OPTest.hpp"

int main()
{
	if (TestQueue::unitTestQueue.size() < 1)
		std::cout << "No tests to run!\n";
	if (TestQueue::unitTestQueue.size() > 1)
		std::cout << "Running Unit Tests:\n\n";
	
	for (int i = 0; i < TestQueue::unitTestQueue.size(); i++)
	{
		TestQueue::unitTestQueue[i]();
		std::cout << '\n';
	}
}
