#include <iostream>

using namespace std;

/**
* Write the function removeEnds() that removes the first and last element in the array, except
* that, if the array size is odd, it removes the first two elements along with the last element. The
* function takes 2 arguments:
*	the array of int that will be modified
*	the size of the array (use size_t as the type)
* 
* Both of these may be changed by the function. The function returns the number of items removed or -1
* if the array has too few elements.
*/


void printArray(int a[], size_t size)
{
	int* begin = a;
	int* end = a + size;
	while (begin != end)
	{
		cout << *begin << " ";
		begin++;
	}
	cout << endl;
}

int removeEnds(int a[], size_t& size)
{
	int removedElements{ 0 };

	int* begin;
	int* end = a + size - 1;

	//// I'm guessing arrays with 1 element is too few, bc if array has odd number of elements(in this case, 1, then 3 is removed)
	//// But array size 2 and up is fine, since even element arrays only get two elements removed
	if (size <= 1) return -1;

	bool isOdd{ false };
	if (size % 2 == 1) // Array size odd
	{
		removedElements = 3;
		isOdd = true;
	}
	// Array size is even
	else removedElements = 2;

	size -= removedElements;

	begin = a; // Reset pointer

	// Shifting elements in array
	while (begin != end)
	{
		if (!isOdd) *begin = *(begin + 1);
		else *begin = *(begin + 2);
		begin++;
	}

	return removedElements;
}




int main()
{
	int a[] = { 1};
	size_t size = sizeof(a) / sizeof(a[0]);
	cout << "Current array: ";
	printArray(a, size);
	cout << "Current size: " << size << endl;

	cout << string(50, '-') << endl;

	int elementsRemoved = removeEnds(a, size);


	// For some reason, evern though array new address is appointed when removeEnds is called, printing the array here resets its address
	//cout << "a here is: " << a << endl;
	cout << "Elements removed: " << elementsRemoved << endl;
	if (elementsRemoved == -1) cout << "Array has too few elements" << endl;
	else
	{
		cout << "New array size: " << size << endl;
		cout << "New array: ";
		printArray(a, size);
	}


	

	return 0;
}

