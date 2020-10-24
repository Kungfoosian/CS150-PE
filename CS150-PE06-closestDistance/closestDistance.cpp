#include <iostream>
#include <cmath>
#include <iomanip>

#include "../stars.cpp"

using namespace std;

vector<Star> closestDistance(const vector<Star>& v)
{
	vector<Star> result;
	double shortestDistance{ -1 };

	for (size_t i{ 0 }, len = v.size(); i < len; i++)
	{
		if (i != len - 1)
		{
			Star currentStar = v.at(i);
			Star nextStar = v.at(i+1);

			double distance = sqrt( pow(nextStar.x - currentStar.x,2) + pow(nextStar.y - currentStar.y,2) );
			cout << currentStar.names << " and " << nextStar.names << " have a distance of: " << distance << endl;
			cout << "Shortest distance now is: " << shortestDistance << endl;

			if (shortestDistance == -1)
			{
				shortestDistance = distance;
				result.push_back(currentStar);
				result.push_back(nextStar);
			}
			else if(distance < shortestDistance)
			{
				result.at(0) = currentStar;
				result.at(1) = nextStar;
				shortestDistance = distance;
			}

		}
	}

	return result;
}


int main()
{
	vector<Star> closest = closestDistance(vStars);

	double distance = sqrt(pow(closest.at(1).x - closest.at(0).x, 2) + pow(closest.at(1).y - closest.at(0).y, 2));
	
	string conclusion = "\tCONCLUSION: " + closest.at(0).names + " and " + closest.at(1).names + " have shortest distance of : " + to_string(distance) + "\t";

	cout << fixed << setprecision(4);

	cout << string(conclusion.size() + 13, '-') << endl;
	cout << "|" << conclusion << "|" << endl;
	cout << string(conclusion.size() + 13, '-') << endl;

	return 0;
}