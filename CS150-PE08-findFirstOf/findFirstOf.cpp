#include <iostream>

using namespace std;


int findFirstOf(const char* s1, const char* s2)
{
	int result{ -1 };
	// Find length of s2
	const char* s2Ptr = s2;
	size_t s2Len{ 0 };
	while (*s2Ptr != '\0')
	{
		s2Len++;
		s2Ptr++;
	}

	s2Ptr = s2;

	const char* s1Ptr = s1;
	bool found{ false };
	int s1Index{ 0 };
	while (*s1Ptr != '\0')
	{
		size_t counter{ 0 };
		while (counter != s2Len)
		{
			if (*(s1Ptr + counter) == *(s2Ptr + counter))
			{
				found = true;
				counter++;
			}
			else
			{
				found = false;
				break;
			}

		}

		if (found)
		{
			result = s1Index;
			break;
		}
		else
		{
			s1Ptr++;
			s1Index++;
		}
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