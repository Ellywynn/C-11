#include <iostream>
#include <algorithm> // for STL algorithms
#include <vector>

using namespace std;

int main()
{
	vector<int> ints = { 1, 3, 4, 64, 123, 65, 325, 1234 };

	for (const auto& i : ints)
		cout << i << " ";

	cout << '\n';

	// finding min and max elements
	auto min = min_element(ints.begin(), ints.end());
	auto max = max_element(ints.begin(), ints.end() - 5);

	cout << "Min element: " << *min << '\n';
	cout << "Max element[0; end - 5]: " << *max << '\n';

	sort(ints.begin(), ints.end()); // sorts the array in ascending order

	for (const auto& i : ints)
		cout << i << " ";

	cout << '\n';

	// returns the position of the finded element
	// if element has not been found, returns end()
	int toFind = 65;
	auto pos1 = find(ints.begin(), ints.end(), toFind);

	if (pos1 != ints.end())
		cout << "element " << toFind << " has been found!\n";

	toFind = 3210;
	auto pos2 = find(ints.begin(), ints.end(), toFind);

	if (pos2 == ints.end())
		cout << "element " << toFind << " has not been found!\n";

	// reverses the array
	reverse(ints.begin(), ints.end());

	for (const auto& i : ints)
		cout << i << " ";

	vector<int> ints2(20);

	copy(ints.begin(), ints.end(), ints2.begin());

	cout << "\nAfter copy:\n";

	for (const auto& i : ints2)
		cout << i << " ";

	cout << endl;

	cin.get();

	/*
		OUTPUT:
		1 3 4 64 123 65 325 1234
		Min element: 1
		Max element[0; end - 5]: 4
		1 3 4 64 65 123 325 1234
		element 65 has been found!
		element 3210 has not been found!
		1234 325 123 65 64 4 3 1
		After copy:
		1234 325 123 65 64 4 3 1 0 0 0 0 0 0 0 0 0 0 0 0
	*/

	return 0;
}