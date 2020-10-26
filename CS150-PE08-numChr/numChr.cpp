#include <iostream>

using namespace std;

/*
 *	Returns index of the first character in s that matches any letters inside letters
 *  @param [const char*] pointer to first element in s
 *  @param [char]		 a character to find
 *  @return [int]		 number of times that char is found in s
 */
int numChr(const char* s, char c)
{
	int result{ 0 };

	const char* sBegin = s;

	while (*sBegin != '\0')
	{
		if (*sBegin == c) result++;

		sBegin++;
	}
	


	return result;
}







int main()
{
	char s[] = { "eieieoh" };
	char c = 'z';

	int result = numChr(s, c);

	cout << "'" << c << "'" << " is found " << result << " times in \"" << s << "\"" << endl;


	return 0;
}
