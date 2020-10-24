#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void matchIndex(istream& in, ostream& out)
{
	string firstLine, secondLine;
	int lineNo{ 1 };
	while (getline(in, firstLine))
	{
		getline(in, secondLine);
		out << "lines " << lineNo << " and " << lineNo + 1 << ": ";

		// I want to iterate using the shorter line's length
		size_t len = firstLine.size() < secondLine.size() ? firstLine.size() : secondLine.size();

		string results;
		for (size_t i{ 0 }; i < len; i++)
		{
			if (firstLine[i] == secondLine[i]) results += to_string(i) + " ";
		}

		if (results.empty()) out << "none";
		else out << results;

		lineNo += 2;
		out << endl;
	}
}

int main()
{
	ifstream in("Text.txt");
	if (in.fail()) cerr << "Cannot open file" << endl;

	matchIndex(in, cout);
	return 0;
}