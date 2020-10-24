#include <iostream>

using namespace std;


/*
 * the function takes 6 arguments:
 *	the array of int and the size of the array. Both of these may be modified.
 *  the value to insert (100)
 *	the position to insert at (2)
 *  the number of times to insert the value (4)
 *  and the capacity of the array (50).
All of these should be type size_t except for the value which is inserted into the array (and
the array elements themselves), which should be of type int.

The function returns true if the elements can be inserted and false if they cannot. The insertion
could fail because the insert position appeared past the size (although it should be possible to insert
immediately after the last element), or if adding the elements would exceed the capacity of the array.
 */
bool insertTimes(int a[], size_t& size, int valueToInsert, size_t positionToInsert, size_t timesToInsert, size_t arrayCapacity)
{
	bool canBeInserted;

	// Check if position is out of range
	if (positionToInsert < 0 || positionToInsert > size + 1) canBeInserted = false;
	else
	{
		canBeInserted = true;

		// I want to move elements from the end back first to make room for the new elements, then insert the new elements in
		// So end would point to <size of array + times to insert>, and beginning would point to where the elements will be inserted
		int* end = a + size + timesToInsert;
		int* begin = a + positionToInsert;

		while (end != begin)
		{
			*end = *(end - timesToInsert);
			end--;
		}

		// Now we will fill out the space with the valueToInsert by timesToInsert
		begin = a + positionToInsert;
		end = a + positionToInsert + timesToInsert;
		while (begin != end)
		{
			*begin = valueToInsert;
			begin++;
		}


		// New size of array
		size += timesToInsert;
	}

	return canBeInserted;
}

void printArray(int a[], size_t& size)
{
	int* begin = a;
	int* end = a + size;
	while (begin != end)
	{
		if (begin == end - 1) cout << *begin;
		else cout << *begin << ", ";
		begin++;
	}
	//cout << endl;
}

void getResult(int a[], size_t& size, int valueToInsert, size_t atPosition, size_t byHowManyTimes, size_t arrayCapacity, string expectedArray, string expectedBool)
{
	bool ok = insertTimes(a, size, valueToInsert, atPosition, byHowManyTimes, arrayCapacity); //  Expected: [10, 20, 100, 100, 100, 100, 30, 40, 50]
	cout << "Bool returned by function: " << ok << ". Expected: " << expectedBool << "." << endl;
	cout << "Expected: " << expectedArray << ". Found -> [";
	printArray(a, size);
	cout << "]." << endl;
}


int main()
{
	int a[50] = { 10, 20, 30, 40, 50 };
	size_t size = 5;
	

	// TEST CASE
	size_t arrayCapacity = 50;
	int valueToInsert = 100;
	size_t byHowManyTimes = 4;
	size_t atPosition;
	string expectedArray, expectedBool;

	// Insert before beginning of array
	/*atPosition = -1;
	expectedArray = "[10, 20, 30, 40, 50]";
	expectedBool = "false";
	getResult(a, size, valueToInsert, atPosition, byHowManyTimes, arrayCapacity, expectedArray, expectedBool);
	cout << endl;*/

	//// Insert at beginning of array
	/*atPosition = 0;
	expectedArray = "[100, 100, 100, 100, 10, 20, 30, 40, 50]";
	expectedBool = "1";
	getResult(a, size, valueToInsert, atPosition, byHowManyTimes, arrayCapacity, expectedArray, expectedBool);*/
	//cout << endl;

	//// Insert within array
	//atPosition = 2;
	//expectedArray = "[10, 20, 100, 100, 100, 100, 30, 40, 50]";
	//expectedBool = "1";
	//getResult(a, size, valueToInsert, atPosition, byHowManyTimes, arrayCapacity, expectedArray, expectedBool);
	//cout << endl;

	//// Insert at end of array
	//atPosition = size;
	//expectedArray = "[10, 20, 30, 40, 50, 100, 100, 100, 100]";
	//expectedBool = "1";
	//getResult(a, size, valueToInsert, atPosition, byHowManyTimes, arrayCapacity, expectedArray, expectedBool);
	//cout << endl;

	//// Insert at end of array, but position is out of range
	//atPosition = size + 2;
	//expectedArray = "[10, 20, 30, 40, 50]";
	//expectedBool = "-1";
	//getResult(a, size, valueToInsert, atPosition, byHowManyTimes, arrayCapacity, expectedArray, expectedBool);
	//cout << endl;

	


	return 0;
}