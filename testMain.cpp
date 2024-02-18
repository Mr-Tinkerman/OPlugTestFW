#include <iostream>
#include <vector>

#include "OPTest.hpp"

int main()
{
	if (UNIT_TestQueue::UNIT_testQueue.size() < 1)
		std::cout << "No tests to run!\n";
	if (UNIT_TestQueue::UNIT_testQueue.size() > 1)
		std::cout << "Running Unit Tests:\n\n";
	
	for (int i = 0; i < UNIT_TestQueue::UNIT_testQueue.size(); i++)
	{
		UNIT_TestQueue::UNIT_testQueue[i]();
		std::cout << '\n';
	}
}
