#include <iostream>
using namespace std;



bool insertInOrder(int dest[], size_t& destSize, const size_t destCapacity, const int src[], const size_t srcSize)
{
	bool result;

	if (destSize + srcSize > destCapacity) result = false;
	else
	{
		result = true;

		int* destBegin = dest + destSize;
		int* destEnd = destBegin + srcSize;
		const int* srcBegin = src;
		while (destBegin != destEnd)
		{
			*destBegin = *srcBegin;
			srcBegin++;
			destBegin++;
		}

		// Update destination array size
		destSize += srcSize;


		// Rearrange dest array
		// Resetting destBegin and destEnd pointers
		destBegin = dest;
		destEnd = dest + destSize;
		while (destBegin != destEnd)
		{
			size_t counter = 1;
			while (counter != destEnd - destBegin) // The amount of elements you can compare with decrease as destBegin increase
			{
				// Compare current element with whichever element the counter + destBegin points to, until it's no longer larger than that element
				if (*destBegin > * (destBegin + counter))
				{
					int placeholder = *destBegin;
					*destBegin = *(destBegin + counter);
					*(destBegin + counter) = placeholder;
				}
				// When current element is no longer larger than that element, increase counter to move current element to the next one
				else counter++;
			}
			
			destBegin++;
		}
	}

	return result;
}







void printArray(int a[], size_t& size)
{
	int* begin = a;
	int* end = a + size;
	cout << "[";
	while (begin != end)
	{
		if (begin == end - 1) cout << *begin << "]";
		else cout << *begin << ", ";
		begin++;
	}
	//cout << endl;
}

void getResult(int a[], size_t& size)
{
	printArray(a, size);
}


int main()
{
	int src[50] = { 5, 7, 4 };
	int dest[50] = { 6, 1 };
	size_t dSize = 2;
	bool ok = insertInOrder(dest, dSize, 50, src, 3);
	printArray(dest, dSize);


	// TEST CASE
	
	return 0;
}