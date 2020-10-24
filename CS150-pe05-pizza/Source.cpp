#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

void clean(string& in)
{
	for (size_t i{ 0 }, len{ in.size() }; i < len; i++)
	{
		char ch = in[i];
		if (!islower(ch)) in[i] = tolower(ch);
	}
}

double getBox(const string& type)
{
	if (type == "slice") return .125;
	else if (type == "half") return .5;
	else if (type == "whole") return 1;
}

void pizza(istream& in, ostream& out)
{
	string line;
	while (getline(in, line))
	{
		int totalBoxCount{ 0 };

		istringstream lineIn(line);
		string portion;
		double box{ 0 };
		while (lineIn >> portion)
		{
			totalBoxCount++;
			clean(portion);
			box += getBox(portion);
			//out << portion << " ";

		}
		out << ceil(box) << " / " << totalBoxCount << " pizza boxes used" << endl;
	}
}

int main()
{
	ifstream in("Text.txt");
	pizza(in, cout);

	return 0;
}