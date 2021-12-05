#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	cout << "Priority queue data structure example!" << endl << endl;

	const int SIZE = 5;
	PriorityQueue<int> que(SIZE);

	que.push(100, 5);

	que.push(120, 3);

	que.push(130, 10);

	que.push(140, 1);

	que.push(150, 3);
	cout << endl;

	// Display the priority queue
	cout << "Priority queue content (Size - " << que.GetSize() << ") : " << endl;

	while (que.isEmpty() == false)
	{
		cout << " Data: " << que.front();
		cout << ", Priority: " << que.frontPriority();
		cout << endl;

		que.pop();
	}

	cout << endl;

	if (que.isEmpty() == true)
	{
		cout << "The container is empty." << endl;
	}
	else
	{
		cout << "The container is NOT empty." << endl;
	}

	return 0;
}