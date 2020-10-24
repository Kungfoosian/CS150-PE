#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void coinFlip(istream& in, ostream& out)
{
	string line;
	while (getline(in, line))
	{
		double headCount{ 0 }, totalCount{ 0 };

		for (size_t i{ 0 }, len{ line.size() }; i < len; i++)
		{
			char current = line[i];
			// Make everything lowercase
			if (!islower(current)) current = tolower(current);
			//out << current;

			// Check each character, if a space, continue the loop
			// If 'h', increment amount of 'h', increment total
			// If 't', increment total
			if (! isspace(current))
			{
				if (current == 'h') headCount++;
				totalCount++;
			}
		}
		// At end of line, find statistic of heads, if percentage more than .5 ==> print "You win!" in addition
		double stats = headCount / totalCount;
		out << fixed << setprecision(1);
		out << int(headCount) << " head";
		
		if (headCount > 1) out << "s ";
		else out << " ";
		
		out<< "(" << stats * 100 << "%)" << endl;

		if (stats > .5) out << "You win" << endl;
		cout << endl;


	}
	
}


int main()
{
	ifstream in("coinFlip.txt");
	if (in.fail()) cerr << "Cannot open file" << endl;

	coinFlip(in, cout);

	return 0;
}