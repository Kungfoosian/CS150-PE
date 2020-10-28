#include <iostream>

using namespace std;

/*
 *	Return the number of times s2 appear in s1
 *	@param s1 pointing to first character in a C-style string
 *	@param s2 pointing to first character in a second C-style string
 *	@return   number of times s2 appear in s1
*/
int numStr(const char* s1, const char* s2)
{
	int count{ 0 };

	// Find length of s2
	const char* s2Beg = s2;

	while (*s2Beg != '\0') s2Beg++;
	int s2Len = s2Beg - s2;
	s2Beg = s2;
	
	// Check each character in s1, if current character matches the first char of s2
	// Then continue in another loop
	const char* s1Beg = s1;
	while (*s1Beg != '\0')
	{
		int counter{ 0 };

		while (*(s1Beg + counter) == *(s2Beg + counter) && counter != s2Len) // While current char in s1 equals to s2 and counter is not length of s2
		{
			if(counter == s2Len - 1) count++; // If counter reach end of s2 (s2Len - 1) then increase count
			counter++;
		}


		s1Beg++;
	}
	
	return count;
}


int main()
{
	char s1[] = { "Hehehahoheeheha" };
	char s2[] = { "ehe" };

	int count = numStr(s1, s2);

	cout << "s2 appears in s1 " << count << " times." << endl; // Expected: 3

	return 0;
}