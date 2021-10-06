#pragma once
#include <cassert>
#include "Array.h"
using namespace std;

template<class T>
class OrderedArray : public Array<T>
{
private:
	bool multBool;
public:
	OrderedArray(int size, bool multiplies) : Array<T>(size) { multBool = multiplies; }
	OrderedArray(OrderedArray& obj) : Array<T>(obj) {};

	//Insertion -- BigO =O(N)
	void push(T val) override
	{
		assert(Array<T>::m_array != nullptr);

		int dup = 0;

		if (multBool == 1)
		{
			for (int d = 0; d < Array<T>::getSize(); d++)
			{
				if (Array<T>::m_array[d] == val)
				{
					dup++;
					cout << "No duplicated values accepted multiples " <<val<< " will be omited." << endl;
				}
			}
		}

		if (dup == 0)
		{
			if (Array<T>::getSize() >= Array<T>::getMaxSize())
			{
				Expand();
			}

			int i, k;
			//Find Indext to insert
			for (i = 0; i < Array<T>::getSize(); i++)
			{
				if (Array<T>::m_array[i] > val)
				{
					break;
				}
			}
			//Shift everythig after the selected index to the right
			for (k = Array<T>::getSize(); k > i; k--)
			{
				Array<T>::m_array[k] = Array<T>::m_array[k - 1];
			}
			//Insert val into the index
			Array<T>::m_array[i] = val;
			Array<T>::setSize(Array<T>::getSize() + 1);
			//return i;
		}
	}

private:
	//Expantion
	bool Expand()
	{
		if (Array<T>::getGrowSize() <= 0)
		{
			return false;
		}

		//Create a new Array
		T* temp = new T[Array<T>::getMaxSize() + (Array<T>::getGrowSize() * 2)];
		assert(temp != nullptr);
		//Copy content from the original array to the new one
		memcpy(temp, Array<T>::m_array, sizeof(T) * Array<T>::getMaxSize());
		//Delete old array
		delete[] Array<T>::m_array;
		//Clean up variable assignments
		Array<T>::m_array = temp;
		temp = nullptr;
		Array<T>::setMaxSize(Array<T>::getMaxSize() + (Array<T>::getGrowSize() * 2));
		Array<T>::setGrowSize(Array<T>::getGrowSize() * 2);

		return true;
	}
};
