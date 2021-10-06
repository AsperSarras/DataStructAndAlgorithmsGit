#pragma once
#include <cassert>
using namespace std;

template<class T>
class OrderedArray
{
private:
	//Var
	T* m_array; // pointer to the beginning of the array

	int m_maxSize;
	int m_growSize;
	int m_numElements;

	// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		// Bitwize divide by 2
		int current = (lowerBound + upperBound) >> 1;

		//Check 1 "Base case": Did we find the searchKey at the current index
		if (m_array[current] == searchKey)
		{
			// We found it, return index
			return current;
		}

		// Check 2 "Base base": are we done searching?
		else if (lowerBound>upperBound)
		{
			// Did not find searchKey within the array
			return -1;
		}
		// Check 3: Which half of the array is searchKey in?
		else
		{
			if (m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current -1 );

			}
		}
		return -1;
	}

public:
	//Constructor
	OrderedArray(int size, int growBy = 1) :
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
	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	//Insertion -- BigO =O(N)
	void push(T val)
	{
		assert(m_array != nullptr);
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;
		//Find Indext to insert
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}
		//Shift everythig after the selected index to the right
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}
		//Insert val into the index
		m_array[i] = val;
		m_numElements++;
		//return i;
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

	//Searching Binary search
	int search(T searchKey)
	{
		// Call to binary search recursive function
		// Binary Search: searchKey, initial lowerBounbd, initialupperBound
		return binarySearch(searchKey, 0, m_numElements - 1);
	}

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
