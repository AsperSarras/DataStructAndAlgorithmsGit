# include <iostream>
#include "UnorderedArray.h";
using namespace std;

int main()
{
	UnorderedArray<int> array(5);
	array.push(2);
	array.push(32);
	array.push(23);
	array.push(89);
	array.push(11);

	//cout << "Bubble sort" << endl;

	//cout << "Before Sorting:";
	//for (int i = 0; i < array.getSize(); i++)
	//{
	//	cout << " " << array[i];
	//}
	//cout << endl;

	//array.bubbleSort();

	//cout << "After Sorting:";
	//for (int i = 0; i < array.getSize(); i++)
	//{
	//	cout << " " << array[i];
	//}
	//cout << endl;

	//cout << "Selection sort" << endl;

	//cout << "Before Sorting:";
	//for (int i = 0; i < array.getSize(); i++)
	//{
	//	cout << " " << array[i];
	//}
	//cout << endl;

	//array.selectionSort();

	//cout << "After Sorting:";
	//for (int i = 0; i < array.getSize(); i++)
	//{
	//	cout << " " << array[i];
	//}
	//cout << endl;

	//cout << "Insertion sort" << endl;

	//cout << "Before Sorting:";
	//for (int i = 0; i < array.getSize(); i++)
	//{
	//	cout << " " << array[i];
	//}
	//cout << endl;

	//array.insertionSort();

	//cout << "After Sorting:";
	//for (int i = 0; i < array.getSize(); i++)
	//{
	//	cout << " " << array[i];
	//}
	//cout << endl;

	cout << "Merge sort" << endl;

	cout << "Before Sorting:";
	for (int i = 0; i < array.getSize(); i++)
	{
		cout << " " << array[i];
	}
	cout << endl;

	array.mergeSort();

	cout << "After Sorting:";
	for (int i = 0; i < array.getSize(); i++)
	{
		cout << " " << array[i];
	}
	cout << endl;

	return 0;
}