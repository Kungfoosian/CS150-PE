#include <iostream>

using namespace std;


int findFirstOf(const char* s1, const char* s2)
{
	int result{ -1 };
	
	const char* s1Ptr = s1;

	while (*s1Ptr != '\0')
	{
		size_t counter{ 0 };
		while (*(s2 + counter) != '\0')
		{
			if (*(s1Ptr + counter) == *(s2 + counter))
			{
				if (*(s2 + counter + 1 == '\0')) return s1Ptr - s1; // check if counter is at end of s2, it would only get there if everything matched so far
				else counter++;
			}
			else break;
		}

		s1Ptr++;
	}

	return result;
}



int main()
{
	findFirstOf("aaaiii", "aia");

	//cout << "HERE" << endl;
	cout << findFirstOf("eieioh", "eio") << endl; // Expected: 2 (index of second e)
	//cout << findFirstOf("aaaiii", "aia") << endl; // Expected: -1 (aia not inside aaaiii)
	return 0;
}