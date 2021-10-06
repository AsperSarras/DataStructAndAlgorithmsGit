//Simple recursive algorithm
#include <iostream>
using namespace std;

//Print down the given number until we reach 1
void PrintNumReverse(int x)
{
	//Base Case
	if (x <= 0)
	{
		return;
	}

	cout << " " << x;
	//Tail recursion (nothing comes after it)
	PrintNumReverse(x - 1);
}

int main()
{
	cout << "Recursion Example" << endl;
	cout << "Here is a recursive call: " << endl;

	//Call a recursive function
	PrintNumReverse(5);

	return 0;
}