#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
using namespace std;


int main()
{
	OrderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(85);
	array.push(23);
	array.push(82);
	
	array[2] = 122;

	array.pop();
	array.remove(2);

	cout << "Unordered array contents: ";

	for ( int i =0; i < array.getSize(); i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	cout << "Search for 53 was found at index: ";
	cout << array.search(23) << endl;

	return 0;
}