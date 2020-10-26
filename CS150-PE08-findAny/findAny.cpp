#include <iostream>

using namespace std;

/*
 *	Returns index of the first character in s that matches any letters inside letters
 *  @param [const char*] pointer to first element in s
 *  @param [const char*] pointer to first element in letters
 *  @return [int]		 index of first character in s that matches any letters inside letters
 */
int findAny(const char* s, const char* letters)
{
	int result{ -1 };

	const char* sBegin = s;

	while (*sBegin != '\0')
	{
		const char* lettersBegin = letters;
		while (*lettersBegin != '\0')
		{
			if (*sBegin == *lettersBegin)
			{
				result = sBegin - s;
				break;
			}
			lettersBegin++;
		}

		if (result != -1) break;

		sBegin++;
	}


	return result;
}







int main()
{
	char s[] = { "eieieoh" };
	char letters[] = { "oie" };

	int result = findAny(s, letters);
	
	cout << "Found at index " << result << endl; // Expecting 0 for "e"


	return 0;
}
