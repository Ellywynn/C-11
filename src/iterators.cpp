#include <iostream>
#include <vector>

int main()
{
	// iterators allow to access collection elements. 
	// const iterators have read-only access.
	constexpr size_t SIZE = 20;

	std::vector<int> ints(SIZE);
	
	// vector initialization
	for (size_t i = 0; i < SIZE; ++i)
		ints[i] = i;

	// forward iteration
	// preferred prefix increments(performance boost: temporary variable won't be created)
	for (auto i = ints.begin(); i != ints.end(); ++i)
	{
		if (*i % 2 == 0)
			*i = *i * *i;
	}

	std::cout << "Vector:\n";

	// constant iterators(read-only access)
	for (auto i = ints.cbegin(); i != ints.cend(); ++i)
		std::cout << *i << " ";

	std::cout << '\n';

	std::cin.get();

	/*
		OUTPUT:
		Vector:
		0 1 4 3 16 5 36 7 64 9 100 11 144 13 196 15 256 17 324 19
	*/

	return 0;
}