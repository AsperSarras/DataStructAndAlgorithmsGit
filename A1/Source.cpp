#include <iostream>
#include "Array.h"
#include"OrderedArray.h"
#include"UnorderedArray.h"
using namespace std;

int main()
{
	int multiples = 3;

	cout << "Would you accept multiples? 0=yes. 1=no" << endl;
	cin >> multiples;

	if (multiples > 1 || multiples < 0)
	{
		cout << "Incorrect answer, program will accept multiples" << endl;
		multiples = 0;
	}

	cout << "Ordered Example" << endl;
	//Array<int>a(5);
	OrderedArray<int>ar(5,multiples);
	ar.push(2);
	ar.push(32);
	ar.push(11);
	ar.push(23);
	ar.push(89);
	ar.push(11);

	for (int i = 0; i < ar.getSize(); i++)
	{
		cout << " " << ar[i];
	}
	cout << endl;

	cout << "Merge Sort Example" << endl;
	
	UnorderedArray<int>arr(5);
	arr.push(2);
	arr.push(32);
	arr.push(11);
	arr.push(23);
	arr.push(89);
	arr.push(11);

	cout << "Before Sorting:";
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;

	arr.mergeSort();

	cout << "After Sorting:";
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
	
	return 0;
}