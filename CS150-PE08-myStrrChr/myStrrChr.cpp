#include <iostream>

using namespace std;

/*
 *	Return last index of character that appear in a C-style string, nullptr if no match
 *	@param s	   pointing to first character in a C-style string
 *	@param c	   character to find in s
 *	@return		   last index of c if found in s
*/
const char* myStrrChr(const char* s, char c)
{
	// Find length of s so we can interate in reverse by increment sBeg to '\0', then reverse by decrement it
	const char* sBeg = s;

	while (*sBeg != '\0') sBeg++;

	while (sBeg != s)
	{
		if (*(sBeg - 1) == c) return sBeg - 1;
		sBeg--;
	}

	return nullptr;
}


int main()
{
	char s[] = { "Hehehahoheeheha" };
	char c = 'a';

	const char * foundAt = myStrrChr(s, c);

	//if (foundAt != -1) cout << "Last index found at: " << foundAt << endl; // Expected: 0 for H
	//else cout << "No matching letters" << endl;
	//cout << foundAt << endl;
	if (foundAt != nullptr) cout << foundAt << endl;
	else cout << "Not found" << endl;

	return 0;
}