#pragma once
#include <cassert>
using namespace std;

template<class T>
class UnorderedArray
{
private:
	//Var
	T* m_array; // pointer to the beginning of the array

	int m_maxSize;
	int m_growSize;
	int m_numElements;
public:
	//Constructor
	UnorderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; //Dyanmic allocation
			memset(m_array, 0, sizeof(T) * m_maxSize); //sets a default value to each value of the array
				// memset(block of memory to fill, value to set, how much of the memory we want to set)
			m_growSize = ((growBy > 0) ? growBy : 0); // if GrowBy>0 m_growSize=growBy, else m_growSize=0
		}
	}
	//Destructor
	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	//Insertion (for Unordered Array -- BigO is O(1)
	void push(T val)
	{
		assert(m_array != nullptr); //Debuging purposes

		if (m_numElements >= m_maxSize) //Check if the array need to expand
		{
			Expand();
		}

		//If there is an empty space for a value it adds it and and increase the checker for the last place on the array +1
		m_array[m_numElements] = val;
		m_numElements++;
	}

	//Deletetion
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; // Reduce the last place checker by 1, ignoring the values that are past it
		}
	}
	//Remove an item given an index BigO=O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			return; //May do an exception handling
		}

		// Copy the value from i+1 into i and then i++
		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}

	//Searching linear search
	int search(T val)
	{
		assert(m_array != nullptr);

		//Brute force search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}

	//------------
	// Sorting
	// Bubble Sort -- BigO=O(N^2)
	void bubbleSort()
	{
		assert(m_array != nullptr);

		T temp;

		for (int k = m_numElements - 1; k > 0; k--)
		{
			for (int i = 0; i < k; i++)
			{
				if (m_array[i] > m_array[i + 1])
				{
					temp = m_array[i];
					m_array[i] = m_array[i + 1];
					m_array[i + 1] = temp;
				}
			}
		}

	}
	// Selection Sort -- BigO=O(N^2)
	void selectionSort()
	{
		assert(m_array != nullptr);

		T temp;
		int min = 0;

		for (int k = 0; k < m_numElements; k++)
		{
			min = k;

			for (int i = k + 1; i < m_numElements; i++)
			{
				if (m_array[i] < m_array[min])
				{
					min = i;
				}
			}
		
			if (m_array[k] > m_array[min])
			{
				temp = m_array[k];
				m_array[k] = m_array[min];
				m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- BigO=O(N^2)
	void insertionSort()
	{
		assert(m_array != nullptr);

		T temp;
		int i = 0;

		for (int k = 1; k < m_numElements; k++)
		{
			temp = m_array[k];
			i = k;
			while (i > 0 && m_array[i - 1] >= temp)
			{
				m_array[i] = m_array[i - 1];
				i--;
			}
			m_array[i] = temp;
		}
	}
	// Merge Sort -- BigO=O(N logN)
	void mergeSort()
	{
		assert(m_array != nullptr);

		T* tempArray = new T[m_numElements];
		assert(tempArray != nullptr);

		mergeSort(tempArray, 0, m_numElements - 1);
		delete[] tempArray;
	}
	// -----------
	//Overloaded [] Op
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}

	//Clear
	void clear()
	{
		m_numElements = 0; //Changes the counter to the first value, ignoring the whole arrray
	}

	//Getters
	int getSize() { return m_numElements; }
	int getMaxSize() { return m_maxSize; }
	int getGrowSize() { return m_growSize; }

	//Setters
	int setGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

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
			if (m_array[low] < m_array[mid])
			{
				tempArray[index++] = m_array[low++];
			}
			else
			{
				tempArray[index++] = m_array[mid++];
			}
		}

		while (low <= tempMid)
		{
			tempArray[index++] = m_array[low++];
		}
		while (mid <= upper)
		{
			tempArray[index++] = m_array[mid++];
		}

		for (int i = 0; i< upper - tempLow + 1;i++)
		{
			m_array[tempLow + i] = tempArray[i];
		}
	}
	//Expantion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		//Create a new Array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);
		//Copy content from the original array to the new one
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		//Delete old array
		delete[] m_array;
		//Clean up variable assignments
		m_array = temp;
		temp = nullptr;
		m_maxSize += m_growSize;

		return true;
	}
};
