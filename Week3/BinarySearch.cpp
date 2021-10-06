// Testing recursive binary search
#include <iostream>
#include "OrderedArray.h"
using namespace std;

int main()
{
	cout << "Recursive binary Search Example" << endl;

	OrderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(85);
	array.push(23);
	array.push(82);
	array.push(1);
	array.push(89);
	array.push(30);
	array.push(100);
	array.push(45);

	cout << "Unordered array contents: ";

	for (int i = 0; i < array.getSize(); i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	cout << "Search for 53 was found at index: ";
	cout << array.search(23) << endl;

	return 0;
}