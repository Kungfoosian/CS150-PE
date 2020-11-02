#include <iostream>
using namespace std;

/*
 * Replace all instances of c1 in s with c2
 * @param s		Pointer to first character in s
 * @param c1	Character to look for in s
 * @param c2	Character to replace c1 with
 * @return		Pointer to first character in s
*/
char* replace(char* s, char c1, char c2)
{
	char* sPtr = s;

	while (*sPtr != '\0')
	{
		if (*sPtr == c1) *sPtr = c2;
		sPtr++;
	}
	
	return s;
}



int main()
{
	char s[] = { "eieiohae" };
	char c1 = 'e';
	char c2 = 'w';
	replace(s, c1, c2);

	cout << s << endl;
	return 0;
}