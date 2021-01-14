#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	// Iterator adapters are special iterators those help 
	// to manipulate collection elements

	cout << "INSERT ITERATORS\n\n";

	/// INSERT ITERATORS
	//  These operators help to insert new elements(not to overwrite them)

	// BACK INSETER
	// it allow to insert new element to the back of the collection
	// needs push_back() function
	vector<int> coll1 = { 1,2,3,45,5,4356,23,45,1,345,13245,143,5 };
	vector<int> coll2;

	copy(coll1.begin(), coll1.end(), back_inserter(coll2));

	cout << "Vector: ";
	for (auto& i : coll2)
		cout << i << " ";

	cout << endl;

	// FRONT INSERTER
	// it allow to insert new element in the front of the collection
	// needs push_front() function
	deque<int> d1;
	deque<int> d2;

	for (int i = 0; i < 15; i++)
		d1.push_back(i);

	copy(d1.begin(), d1.end(), front_inserter(d2));

	cout << "Deque: ";

	for (auto& i : d2)
		cout << i << " ";

	cout << endl;

	/// STREAM ITERATORS
	//  They use I\O streams to operate them

	
	cout << "\nSTREAM OPERATORS\n\n";

	vector<string> strcoll; //string collection

	// copying input into the collection
	copy(istream_iterator<string>(cin),
		istream_iterator<string>(), back_inserter(strcoll));

	cout << "Printing with loop:\n";
	for (auto& i : strcoll)
		cout << i << " ";
	
	cout << endl;
	
	// print collection with ostream iterator
	cout << "Printing with stream iterators:\n";
	unique_copy(strcoll.cbegin(), strcoll.cend(),
		ostream_iterator<string>(cout, " "));

	cout << endl;
	
	/// REVERSE ITERATORS
	//  They allow to process collections from end to start

	cout << "\nREVERSE ITERATORS\n\n";

	vector<int> rev; // collection

	// initialization
	for (int i = 1; i <= 15; ++i)
		rev.push_back(i);

	// readonly console reverse out with crbegin() and crend() const iterators
	copy(rev.crbegin(), rev.crend(), ostream_iterator<int>(cout, " "));

	cin.get();

	return 0;
}