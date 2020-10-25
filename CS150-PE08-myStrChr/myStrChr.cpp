#include <iostream>
#include <typeinfo>
using namespace std;
//
///*
// *	Function returns a pointer to the first appearance of a provided character inside s, nullptr if it doesn't
// *	@param	[const char*] points to first character in a C-style string
// *	@param	[char]		  character to look for in the C-style string
// *	@return [pointer]	  pointer to the first appearance of char in C-style string, or nullptr if doesn't find it
// */
const char* myStrChr(const char* s, char c)
{
	const char* result{nullptr};
	const char* beg = s;
	
	while (*beg != '\0')
	{
		if (*beg == c)
		{
			result = beg;
			break;
		}
		else beg++;
	}

	return result;

}





int main()
{
	char myString[] = { "aaebeyyy" };
	char toFind = 'e';
	
	const char* result = myStrChr(myString, toFind);
	if (result != NULL)
	{
		// result returns a pointer, but if prints to console, then it prints the rest of the c_string starting from that pointer
		// So to get the index of the first matching char encountered, do result - myString
		cout << "First found at index: " << result - myString << endl;
	}
	else cout << "Can't find" << endl;
	
	return 0;
}
