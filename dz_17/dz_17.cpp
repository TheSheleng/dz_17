#include <iostream>

#include "Array.h"

using namespace std;

int main()
{
	Array<int> test;

	test.SetSize(11, 5);

	test.Add(1);
	test.Add(2);
	test.Add(3);

	test.FreeExtra();

	test.Add(4);

	test[1] = 5;

	Array<int> test_2;

	test_2.Add(5);
	test_2.Add(6);

	test.Append(test_2);

	test_2 = test;

	test.RemoveAt(4);
	test.InsertAt(3, 5);

	for (int i = 0; i < test.GetUpperBound(); i++)cout << test.GetData()[i];
}