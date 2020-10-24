#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

void cleanType(string& input)
{
	for (size_t i{ 0 }, len{ input.size() }; i < len; i++)
	{
		char current = input[i];
		if (!islower(current)) input[i] = tolower(current);
	}
}

double getWorth(const int amount, const string type)
{
	double coinValue{ 0 };

	if (type == "pennies") coinValue = .01;
	else if (type == "nickels") coinValue = .05;
	else if (type == "dimes") coinValue = .1;
	else if (type == "quarters") coinValue = .25;

	return amount * coinValue;
}


void countCoins(istream& in, ostream& out)
{
	int amount;
	double totalWorth{ 0 };
	string type;

	while (!in.eof())
	{
		in >> amount >> type;
		cleanType(type);

		totalWorth += getWorth(amount, type);



		//out << amount << " " << type << endl;
	}
	out << fixed << setprecision(2);
	out << "Total money: $" << totalWorth << endl;
}


int main()
{
	ifstream in("Text.txt");
	if (in.fail()) cerr << "Cannot open file" << endl;

	countCoins(in, cout);
	return 0;
}


