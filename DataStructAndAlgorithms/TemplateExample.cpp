//Generics classes or functions
//Compare 2 things, Return smallest and then the largest.
#include <iostream>
using namespace std;

//Template function
//Check and return smallest
template<class T>
T min_func(T lVal, T rVal)
{
	if (lVal > rVal)
	{
		return rVal;
	}

	return lVal;
}

//Template function
//Check and return largest
template<class T>
T max_func(T lVal, T rVal)
{
	if (lVal > rVal)
	{
		return lVal;
	}

	return rVal;
}

//Implement a template class
template <class T>
class TemplateClass
{
private:
	T m_val;

public:
	TemplateClass(T val)
	{
		m_val = val;
	}
	
	//Overload to let the Function work with classes and not only primitive data
	bool operator<(TemplateClass& rVal)
	{
		return m_val < rVal.GetVal();
	}

	bool operator>(TemplateClass& rVal)
	{
		return m_val > rVal.GetVal();
	}


	//Get
	T GetVal()
	{
		return m_val;
	}
};

//Main function
/*
int main()
{
	//Ex1
	cout << "Template Example" << endl << endl;
	cout << "Min= " << min_func(56.8, 43.8) << ", Max= " << max_func(56.8, 43.8)<<endl;
	cout << "Min= " << min_func('a', 'c') << ", Max= " << max_func('a', 'c') << endl;

	//Ex2
	cout << "Max (objects)= " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();

	return 0;
}
*/

