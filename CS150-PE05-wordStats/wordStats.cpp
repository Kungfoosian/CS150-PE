#include <iostream>
#include <fstream>

using namespace std;

void wordStats(istream& in, ostream& out)
{
	string word;
	double counter{ 0 }, average{ 0 }, lengthSum{ 0 };
	while (in >> word)
	{
		counter++;
		lengthSum += word.size();
		average = lengthSum / counter;
	}

	out << "Total word     = " << counter << endl;
	out << "Average length = " << average << endl;
}

int main()
{
	ifstream in("Text.txt");
	wordStats(in, cout);

	return 0;
}