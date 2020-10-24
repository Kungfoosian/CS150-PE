#include <iostream>
#include <string>


#include "../stars.cpp"

using namespace std;

vector<size_t> magnitudeBetween(const vector<Star>& v, const double& lowerBound, const double& upperBound)
{
	vector<size_t> result;

	for (size_t i{ 0 }; i < v.size(); i++)
	{
		Star currentStar = v.at(i);
		if (lowerBound <= currentStar.magnitude && currentStar.magnitude <= upperBound) result.push_back(i);
	}

	return result;
}

int main()
{
	double lowerBound = 1;
	double upperBound = 3;

	vector<size_t> result = magnitudeBetween(vStars, lowerBound, upperBound);
	if (result.size() == 0) cout << "No stars found" << endl;
	else
	{
		cout << "Stars whose draper is between " << lowerBound << " and " << upperBound << " is found at index: ";
		for (auto i{ 0 }; i < result.size(); i++)
		{
			cout << result.at(i);
			if (i != result.size() - 1) cout << ", ";
			else cout << "." << endl;
		}
	}

	return 0;
}