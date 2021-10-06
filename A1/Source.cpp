#include <iostream>
#include "Array.h"
#include"OrderedArray.h"
#include"UnorderedArray.h"
using namespace std;

int main()
{
	//Array<int>a(5);
	UnorderedArray<int>ar(5);
	//UnorderedArray<int>ar(5);
	ar.push(2);
	ar.push(32);
	ar.push(23);
	ar.push(89);
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;
	ar.push(11);
	cout << ar.getMaxSize() << endl;

	cout << "Bubble sort" << endl;

	cout << "Before Sorting:";

	for (int i = 0; i < ar.getSize(); i++)
	{
		cout << " " << ar[i];
	}
	cout << endl;

	ar.mergeSort();

	cout << "After Sorting:";
	for (int i = 0; i < ar.getSize(); i++)
	{
		cout << " " << ar[i];
	}
	cout << endl;
	
	return 0;
}