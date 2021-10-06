// Double factorial (Semi-Factorial) 9!! = 9*7*5*3*1
#include <iostream>
#include <cassert>
using namespace std;

// Single factorial
int factorial(int x)
{
	assert(x >= 0);

	// Base case
	if (x == 0)
	{
		// I know that 0! = 1 ALWAYS
		return 1;
	}

	// Tail recursion
	return (factorial(x - 1) * x);
}

// Double factorial
int doubleFactorial(int x)
{
	assert(x >= 0);

	// Base case
	if (x == 0 || x == 1)
	{
		return 1;
	}

	return (doubleFactorial(x - 2) * x);
}

// Main
int main()
{
	cout << "FACTORIALS!!" << endl;

	cout << "The factorial of 5: "<< factorial(5) <<endl;
	
	cout << "The double factorial of 7 is: " << doubleFactorial(7);


	return 0;
}
