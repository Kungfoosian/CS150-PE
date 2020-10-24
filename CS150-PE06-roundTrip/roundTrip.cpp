#include <iostream>
#include <cmath>
#include <iomanip>

#include "../stars.cpp"

using namespace std;

/*
 *	@param  a vector of stars
 *	@param  the average magnitude of all the stars visited
 *	@return the round-trip distance
 */
double roundTrip(const vector<Star>& v, double& average)
{
	double result{ 0 }, counter{ 0 };
	
	for (size_t i{ 0 }; i < v.size(); i++)
	{
		Star currentStar = v.at(i);
		average += currentStar.magnitude;
		//cout << "average is: " << average << endl;
		if (i != v.size() - 1)
		{
			Star nextStar = v.at(i + 1);

			result += sqrt( pow( nextStar.x - currentStar.x ,2) + pow( nextStar.y - currentStar.y, 2) );
		}
		else
		{
			result += sqrt(pow(v.at(i).x - v.at(0).x, 2) + pow(v.at(i).y - v.at(0).y, 2));
		}
		counter++;
	}
	average /= counter;

	return result;
}

int main()
{
	double average{ 0 };
	double distance = roundTrip(vStars, average);

	cout << fixed << setprecision(2);
	cout << "Round trip distance is: " << distance << " and average is: " << average << endl;
	return 0;
}