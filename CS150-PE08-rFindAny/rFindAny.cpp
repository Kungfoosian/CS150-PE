#include <iostream>

using namespace std;

/*
 *	Return last index of any character that appear in a C-style string, -1 if no match
 *	@param s	   pointing to first character in a C-style string
 *	@param letters pointing to first character in a second C-style string
 *	@return		   last index of any character in letters found in f
*/
int rFindAny(const char* s, const char* letters)
{
	int index{ -1 };

	// Find length of s so we can interate in reverse by increment sBeg until it hits '\0', then decrement to read elements in reverse
	const char* sBeg = s;

	while (*sBeg != '\0') sBeg++;

	const char* lettersBeg = letters;

	while (sBeg != s)
	{
		while (*lettersBeg != '\0')
		{
			if (*(sBeg - 1) == *lettersBeg) return sBeg - s - 1;

			lettersBeg++;
		}
		lettersBeg = letters;
		sBeg--;
	}

	return index;
}


int main()
{
	char s1[] = { "Hehehahoheeheha" };
	char letters[] = { "zyH" };

	int foundAt = rFindAny(s1, letters);

	if (foundAt != -1) cout << "Last index found at: " << foundAt << endl; // Expected: 0 for H
	else cout << "No matching letters" << endl;

	return 0;
}