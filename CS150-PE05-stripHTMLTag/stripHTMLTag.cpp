#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

void stripHTMLTag(istream& in, ostream& out)
{
	string line;
	char ch;
	bool inTag{ false };
	while (!in.eof())
	{
		ch = in.get();
		if (ch == '<') inTag = true;
		else if (ch == '>')
		{
			inTag = false;
			continue;
		}

		if (inTag == false) out << ch;
	}
}


int main()
{
	ifstream infile("Text1.txt");
	if (infile.fail()) cerr << "Can't open file" << endl;

	stripHTMLTag(infile, cout);

	return 0;
}