#include <iostream>

using namespace std;
//
///*
// *	Function returns a pointer to the first appearance of a provided character inside s, nullptr if it doesn't
// *	@param	[const char*] points to first character in a first C-style string
// *	@param	[const char*] points to first character in a second C-style string
// *	@return [pointer]	  pointer to the first appearance of second string in first string, nullptr if not
// */
const char* findFirst(const char* s1, const char* s2)
{
	const char* result{ nullptr };
	const char* beginS1 = s1;
	const char* beginS2 = s2;


	// Then look for s2 in s1
	// Check each character in s1
	// If current character matches with first char of s2, then continue from there
	// Else, increment s1 and redo
	while (*beginS1 != '\0')
	{
		size_t counter{ 0 };


		while (*(beginS2 + counter) != '\0')
		{
			if(*(beginS1 + counter) == *(beginS2 + counter))
			{
				result = beginS1;
				// Check if counter is at the end or not
				if (*(beginS2 + counter + 1) == '\0') return result;
				else counter++;
			}
			else
			{
				result = nullptr;
				break;
			}
		}
		beginS1++;
	}

	return result;

}





int main()
{
	char s1[] = { "eieieoh" };
	char s2[] = { "eo" };

	const char* result = findFirst(s1, s2);
	//cout << result << endl;
	if (result != NULL)
	{
		// result returns a pointer, but if prints to console, then it prints the rest of the c_string starting from that pointer
		// So to get the index of the first matching char encountered, do result - myString
		cout << "First found at index: " << result - s1 << endl;
	}
	else cout << "Can't find" << endl;


	return 0;
}
