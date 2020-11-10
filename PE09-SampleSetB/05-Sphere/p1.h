
#ifndef P1_H
#define P1_H
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = std::acos(-1);

class Sphere
{
private:
	double r_;
public:
	Sphere(double r = 0);
	double radius() const;
	double volume() const;
	double area() const;
	std::string toString() const;
	Sphere operator* (double d);
	void operator/=(double d);
};




#endif