#pragma once
#include <cassert>
#include "Array.h"
using namespace std;

template<class T>
class UnorderedArray : public Array<T>
{
public:
	//Constructor
	UnorderedArray(int size) : Array<T>(size) {}
	UnorderedArray(UnorderedArray& obj) : Array<T>(obj) {};

	void push(T val) override
	{
		assert(Array<T>::m_array != nullptr); //Debuging purposes

		if (Array<T>::getSize() >= Array<T>::getMaxSize()) //Check if the array need to expand
		{
			Expand();
		}

		//If there is an empty space for a value it adds it and and increase the checker for the last place on the array +1
		Array<T>::m_array[Array<T>::getSize()] = val;
		Array<T>::setSize(Array<T>::getSize()+1);
	}

	//------------
	// Sorting
	// Bubble Sort -- BigO=O(N^2)
	void bubbleSort()
	{
		assert(Array<T>::m_array != nullptr);

		T temp;

		for (int k = Array<T>::getSize() - 1; k > 0; k--)
		{
			for (int i = 0; i < k; i++)
			{
				if (Array<T>::m_array[i] > Array<T>::m_array[i + 1])
				{
					temp = Array<T>::m_array[i];
					Array<T>::m_array[i] = Array<T>::m_array[i + 1];
					Array<T>::m_array[i + 1] = temp;
				}
			}
		}

	}
	// Selection Sort -- BigO=O(N^2)
	void selectionSort()
	{
		assert(Array<T>::m_array != nullptr);

		T temp;
		int min = 0;

		for (int k = 0; k < Array<T>::getSize(); k++)
		{
			min = k;

			for (int i = k + 1; i < Array<T>::getSize(); i++)
			{
				if (Array<T>::m_array[i] < Array<T>::m_array[min])
				{
					min = i;
				}
			}
		
			if (Array<T>::m_array[k] > Array<T>::m_array[min])
			{
				temp = Array<T>::m_array[k];
				Array<T>::m_array[k] = Array<T>::m_array[min];
				Array<T>::m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- BigO=O(N^2)
	void insertionSort()
	{
		assert(Array<T>::m_array != nullptr);

		T temp;
		int i = 0;

		for (int k = 1; k < Array<T>::getSize(); k++)
		{
			temp = Array<T>::m_array[k];
			i = k;
			while (i > 0 && Array<T>::m_array[i - 1] >= temp)
			{
				Array<T>::m_array[i] = Array<T>::m_array[i - 1];
				i--;
			}
			Array<T>::m_array[i] = temp;
		}
	}
	// Merge Sort -- BigO=O(N logN)
	void mergeSort()
	{
		assert(Array<T>::m_array != nullptr);

		T* tempArray = new T[Array<T>::getSize()];
		assert(tempArray != nullptr);

		mergeSort(tempArray, 0, Array<T>::getSize() - 1);
		delete[] tempArray;
	}
	// -----------
	
	//Private Functions
private:
	//Recursive merge Sort{
	void mergeSort(T* tempArray, int lowerBound, int upperBound)
	{
		if (lowerBound == upperBound)
		{
			return;
		}

		int mid = (lowerBound + upperBound) >> 1;

		mergeSort(tempArray, lowerBound, mid);
		mergeSort(tempArray, mid + 1, upperBound);

		merge(tempArray, lowerBound, mid + 1, upperBound);
	}
	
	void merge(T* tempArray, int low, int mid, int upper)
	{
		int tempLow = low, tempMid = mid - 1;
		int index = 0;

		while (low <= tempMid && mid <= upper)
		{
			if (Array<T>::m_array[low] < Array<T>::m_array[mid])
			{
				tempArray[index++] = Array<T>::m_array[low++];
			}
			else
			{
				tempArray[index++] = Array<T>::m_array[mid++];
			}
		}

		while (low <= tempMid)
		{
			tempArray[index++] = Array<T>::m_array[low++];
		}
		while (mid <= upper)
		{
			tempArray[index++] = Array<T>::m_array[mid++];
		}

		for (int i = 0; i< upper - tempLow + 1;i++)
		{
			Array<T>::m_array[tempLow + i] = tempArray[i];
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
