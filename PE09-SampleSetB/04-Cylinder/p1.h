#ifndef P1_H
#define P1_H
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = std::acos(-1);

class Cylinder
{
private:
	double r_, h_;
public:
	Cylinder();
	Cylinder(double, double);
	double radius() const;
	double height() const;
	double volume() const;
	double area() const;
	friend ostream& operator<<(ostream&, Cylinder);
	Cylinder operator~(); // Invert radius -> height (vice versa), original stays the same
	void operator!(); // Flipping members?
};


#endif