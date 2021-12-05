#pragma once

#include "PriorityQueueLinkedList.h"

template<class T>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	// Priority Queue Functions
	void push(T val, int priority)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push_Back(val,priority);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			if (it.isValid())
			{
				while (it.isValid())
				{

					if (it.getPriority() > priority)
					{
						break;
					}
					it++;
				}
			}

			if (it.isValid())
			{
				m_elements.Insert_Before(it, val,priority);
			}
			else
			{
				m_elements.Push_Back(val,priority);
			}
		}
	}

	void pop()
	{
		m_elements.Pop_Front();
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}

	//
	T& frontPriority()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return it.getPriority();
	}

	// Helper functions
	int GetSize()
	{
		return m_elements.GetSize();
	}

	int GetMaxSize()
	{
		return m_size;
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}

private:
	LinkedList<T> m_elements; // Priority Queue Linked List
	int m_size;
};