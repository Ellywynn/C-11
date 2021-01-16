#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v1(5);	// creating vector with elements initialization

	vector<int> v2;
	v2.reserve(80);		// creates 80 elements w/o initializdation

	// !reallocation is expensive!

	vector<int> v3; // 50 ints

	for (int i = 0; i < 15; i++)
		v3.push_back(std::move(i));

	// shrink_to_fit() is used to save memory space
	cout << "Vector capacity: " << v3.capacity() << endl;
	v3.shrink_to_fit();
	cout << "Vector capacity after shrink: " << v3.capacity() << endl;

	// it doesn't change anything because capacity is
	// already big enough to handle 10 elements
	v3.reserve(10);

	cout << "After capacity: size = " << v3.size() << "; capacity = " << v3.capacity() << endl;

	v3.assign(8, 20); // recreates v3 with 8 elements of value 20

	cout << "Vector after assign: ";

	for (auto& i : v3)
		cout << i << ' ';

	cout << endl;

	v1.clear();
	v2.clear();
	v3.clear();

	// creating vector with init list
	vector<float> v4 = { 1.1,2.2,3.3,4.4,5.5,6.6 };
	v4.at(3) = 70.7f; // assings the fourth element

	cout << "Vector before erasing: ";

	for (auto& i : v4)
		cout << i << ' ';

	cout << "\nVector after erasing: ";

	// finds the position of the element with this value
	auto pos = std::find(v4.begin(), v4.end(), 70.7f);
	// if there is element with this value, erases it
	if (pos != v4.end())
		v4.erase(pos);

	for (auto& i : v4)
		cout << i << ' ';

	cout << endl;

	cin.get();

	return 0;
}