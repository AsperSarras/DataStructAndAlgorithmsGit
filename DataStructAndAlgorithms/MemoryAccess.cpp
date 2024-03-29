/*
What is the difference form accessing 

Array [0][0][0] to Array [0][0][1]
				vs
Array [0][0][0] to Array [1][0][0]
*/

#include <time.h>
#include <iostream>
using namespace std;

const int n = 750;
float TestData[n][n][n];

//Helper Function that will convert clock ticks to milliseconds
double diffClock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2; // diffenrence betwen 2 separate clock ticks
	double diffms = (diffticks * 10 / CLOCKS_PER_SEC);
	return diffms;
}

//Add values row by row
void row_ordered()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				TestData[i][j][k] = 1;
			}

		}
	}
}

//Add values column by column
void col_ordered()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				TestData[k][j][i] = 2;
			}

		}
	}
}

int main()
{
	clock_t begin = clock(); // Current number of clocks ticks elapsed up to this point
	row_ordered();
	clock_t end = clock(); // Current number of clock ticks elapsed up to this point
	cout << "Time elapsed (row): " << diffClock(end, begin) << " ms" << endl;

	begin = clock(); // Current number of clocks ticks elapsed up to this point
	col_ordered();
	end = clock(); // Current number of clock ticks elapsed up to this point
	cout << "Time elapsed (col): " << diffClock(end, begin) << " ms" << endl;
}