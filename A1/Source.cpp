#include <iostream>
#include "Array.h"
#include"OrderedArray.h"
#include"UnorderedArray.h"
using namespace std;

int main()
{
	//Array<int>a(5);
	Array<int>ar(5);
	//UnorderedArray<int>ar(5);
	ar.push(2);
	cout << ar[0] << endl;
	ar.push(32);
	cout << ar.getMaxSize() << endl;
	ar.push(23);
	cout << ar.getMaxSize() << endl;
	ar.push(89);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	
	cout << "Bubble sort" << endl;

	cout << "Before Sorting:";

	for (int i = 0; i < ar.getMaxSize(); i++)
	{
		cout << " " << ar[i];
	}
	cout << endl;

	return 0;
}