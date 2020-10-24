#include <string>
#include <iostream>

#include "../stars.cpp"

using namespace std;

/**
  *	
  * @param a vector of stars
  * @param star name/part of a star name to look for
  * @return draper numbers of the stars where the name was found
  */
vector<int> findStars(const vector<Star>& v, string starName)
{
	vector<int> result;

	for (size_t i{ 0 }; i < v.size(); i++)
	{
		//cout << vStars.at(i).names << endl;
		Star currentStar = v.at(i);
		size_t found = currentStar.names.find(starName);

		if (found != string::npos) result.push_back(currentStar.draperNumber);

	}

	return result;
}

int main()
{
	cout << "Enter a name, or part of a name to search: ";

	string input;
	getline(cin, input);

	vector<int> result = findStars(vStars, input);
	if (result.size() == 0) cout << "No stars found" << endl;
	else
	{
		cout << "Drapers found: "; 
		for (auto i{ 0 }; i < result.size(); i++)
		{
			cout << result.at(i);
			if (i != result.size() - 1) cout << ", ";
			else cout << "." << endl;
		}
	}

	return 0;
}