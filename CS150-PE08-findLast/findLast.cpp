#include <iostream>

using namespace std;
//
///*
// *	Function returns a pointer to the LAST appearance of a provided character inside s, nullptr if it doesn't
// *	@param	[const char*] points to first character in a first C-style string
// *	@param	[const char*] points to first character in a second C-style string
// *	@return [pointer]	  pointer to the LAST appearance of second string in first string, nullptr if not
// */
const char* findLast(const char* s1, const char* s2)
{
	const char* result{ nullptr };
	
	const char* s2Begin = s2;
	// Get length of s2
	while (*s2Begin != '\0') s2Begin++;
	size_t s2Len = s2Begin - s2;
	s2Begin = s2;
	const char* s2End = s2 + s2Len;

	const char* s1Begin = s1;
	// Get length of s1
	while (*s1Begin != '\0') s1Begin++;
	size_t s1Len = s1Begin - s1;
	s1Begin = s1;
	const char* s1End = s1 + s1Len;

	// *(s2End - 1) to get current element from the back


	// Then look for s2 in s1
	// Check each character in s1 from end to begin
	// If current character matches with last char of s2, then continue from there
	// Else, decrement s1 and redo
	while (s1End != s1Begin)
	{
		size_t counter{ 0 };


		while (s2End - counter != s2Begin)
		{
			if (*(s1End - counter - 1) == *(s2End - counter - 1))
			{
				result = s1End;
				// Check if counter is at the beginning or not
				if ((s2End - counter - 1) == s2Begin) return result - s2Len; // Since we are going back to front, the result returned technically
																			 // *would* be the last encountered element, if we are counting back to front
																			 // So to get correct index when reading front to back, subtract result by length of s2
				else counter++;
			}
			else
			{
				result = nullptr;
				break;
			}
		}
		s1End--;
	}

	return result;

}





int main()
{
	char s1[] = { "eieieoh" };
	char s2[] = { "ez" };

	const char* result = findLast(s1, s2);
	//cout << result << endl;
	if (result != NULL)
	{
		// result returns a pointer, but if prints to console, then it prints the rest of the c_string starting from that pointer
		// So to get the index of the first matching char encountered, do result - myString
		cout << "Last found at index: " << result - s1 << endl;
	}
	else cout << "Can't find" << endl;


	return 0;
}
