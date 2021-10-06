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
		m_array(NULL), m_maxSize(size), m_growSize(0), m_numElements(0)
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
