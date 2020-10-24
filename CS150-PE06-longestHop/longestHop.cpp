#include <iostream>
#include <cmath>
#include <iomanip>

#include "../stars.cpp"

using namespace std;


vector<Star> longestHop(const vector<Star>& v)
{
	vector<Star> result = {};
	double lastLongestHop{ 0.0 };

	for (size_t i{ 0 }; i < v.size(); i++)
	{
		if (i != v.size() - 1)
		{
			Star currentStar = v.at(i);
			Star nextStar = v.at(i + 1);

			//cout << nextStar.x << " " << currentStar.x << endl;
			double distance = sqrt( pow( nextStar.x - currentStar.x, 2 ) + pow(nextStar.y - currentStar.y, 2));
			//cout << distance << "---" << lastLongestHop << endl;
			if (distance > lastLongestHop)
			{
				lastLongestHop = distance;
				if (result.size() == 0)
				{
					result.push_back(currentStar);
					result.push_back(nextStar);
				}
				else
				{
					result.at(0) = currentStar;
					result.at(1) = nextStar;
				}
			}

		}

	}

	return result;
}

int main()
{
	vector<Star> result = longestHop(vStars);
	if (result.size() == 0) cout << "No stars found" << endl;
	else
	{
		double distance = sqrt(pow(result.at(1).x - result.at(0).x, 2) + pow(result.at(1).y - result.at(0).y, 2));
		cout << fixed << setprecision(3);
		cout << result.at(0).names << " and " << result.at(1).names << " has longest distance of: " << distance << endl;
	}

	return 0;
}