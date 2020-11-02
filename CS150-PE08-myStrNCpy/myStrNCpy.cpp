#include <iostream>
using namespace std;

/*
 * Copy characters from src to dest, but no more than max - 1 characters
 * @param dest  where to copy src to
 * @param src	Pointing to first char in c-style string
 * @param max	Maximum size of dest buffer
 * @return		Pointer to first character in dest
*/
char* myStrNCpy(char* dest, const char* src, int max)
{
	char* destPtr = dest;

	while (max - 1 != 0)
	{
		*destPtr = *src;
		destPtr++;
		src++;

		max--;
	}
	*destPtr = '\0';
	return dest;
}



int main()
{
	const char src[] = { "Hello World!!" };
	char dest[3];
	int max = 3;
	myStrNCpy(dest, src, max);

	cout << dest << endl;
	return 0;
}