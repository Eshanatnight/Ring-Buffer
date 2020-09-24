#include "CircularBuffer.hpp"
#include <iostream>
#include <vector>

std::vector<int> range(int _end)
{
	std::vector<int> _range;
	int range = 0;
	while (range < _end)
	{
		_range.push_back(range++);
	}
	return _range;
}

std::vector<int> range(int _start, int _end)
{
	std::vector<int> _range;
	while (_start < _end)
	{
		_range.push_back(_start++);
	}
	return _range;
}

int main()
{
	CircularBuffer<int> ew{ 1,2,5,8, 6, 7, 88, 97,105 };

	ew.add(16);

	for (auto i : ew)
	{
		std::cout << i << std::endl;
	}
}