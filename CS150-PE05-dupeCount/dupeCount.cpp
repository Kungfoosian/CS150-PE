#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void dupeCount(istream& in, ostream& out)
{
	string line;
	while (getline(in, line))
	{
		string lastWord{ "" };
		int wordCount{ 1 };
		istringstream lineIn(line);
		while (!lineIn.eof())
		{
			string newWord;
			lineIn >> newWord;
			//out << newWord << " ";
			// If new word is different than last word, 
			//		then check if its word count is more than 1. If it is, print the last word * its word count
			//		(If it's not more than 1 (<= 1)) Update it to new word and set its count to 1
			// Else (if new word is same as last word)
			//		then increment its word count

			if (newWord != lastWord)
			{
				if (wordCount > 1) out << lastWord << "*" << wordCount << " ";
				lastWord = newWord;
				wordCount = 1;
			}
			else wordCount++;
		}
		// For input reaching end of line but has duplicate count > 1
		if(lineIn.eof() && wordCount > 1) out << lastWord << "*" << wordCount << " ";
		out << endl; // Finishing off the line
	}
}



int main()
{
	ifstream in("dupeCount.txt");
	if (in.fail()) cerr << "Cannot open file" << endl;

	dupeCount(in, cout);
	return 0;
}