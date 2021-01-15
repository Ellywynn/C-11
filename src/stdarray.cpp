#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	// creating arrays
	array<int, 10> a1, a2;

	// initializing arrays
	for (int i = 1; i <= a2.size(); ++i)
		a2[i - 1] = i * i;

	// move constructor(move elements)
	a1 = std::move(a2);

	// creating array using init list
	array<int, 10> a = { 1,2,3,4,5 };

	// fills all elements with argument value
	a.fill(50);

	
	a1.back() = 200; // returns the last element
	a1.front() = 14; // returns the first element

	int sum = 0;
	for_each(a1.begin(), a1.end(), [&sum](int val)
		{
			sum += val;
		});

	cout << "a1 = ";

	// range-based for loop
	for (auto& a : a1)
		cout << a << ' ';

	cout << endl;

	cout << "The sum of the a1: " << sum << endl;

	transform(a1.begin(), a1.end(), a1.begin(), negate<int>());

	cout << "a1 after transform: ";

	for (const auto& e : a1)
		cout << e << ' ';

	cout << endl;

	cin.get();

	return 0;
}