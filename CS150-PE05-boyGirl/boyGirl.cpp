#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

/**
 *	Count the number of boys, girls, and the difference between the sum of boys and girls
 * @param in input stream
 * @param out output stream
 */
void boyGirl(istream& in, ostream& out)
{

	string line{""};
	while (getline(in, line))
	{
		// Prints the input
		out << line << endl;

		string name;
		bool isBoy{ true }, isGirl{ false };
		int boySum{ 0 }, boyCount{ 0 }, girlSum{ 0 }, girlCount{ 0 };

		// Create istringstream to read the whole line
		istringstream lineIn(line);
		while (!lineIn.eof())
		{
			
			int n;
			lineIn >> name >> n;

			// Switch between boy and girl
			if (isBoy)
			{
				isBoy = false;
				isGirl = true;
				boyCount++;
				boySum += n;
			}
			else
			{
				isGirl = false;
				isBoy = true;
				girlCount++;
				girlSum += n;
			}
		}

		out << boyCount << " boys, " << girlCount << " girls" << endl;
		out << "Difference between boys' and girls' sums: " << abs(boySum - girlSum) << endl;

	}
}

int main()
{
	/*cout << "Enter file to test: ";
	string fileInput;
	cin >> fileInput;*/
	ifstream infile("boyGirl.txt");

	if (infile.fail()) cerr << "Error: Can't open file" << endl;
	
	boyGirl(infile, cout);

	return 0;
}