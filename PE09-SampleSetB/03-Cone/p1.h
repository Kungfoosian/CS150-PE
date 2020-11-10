
#ifndef P1_H
#define P1_H
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = std::acos(-1);

class Cone
{
private:
	double r_, h_;
public:
	Cone();
	Cone(double, double);
	double radius() const;
	double height() const;
	double volume() const;
	double area() const;
	friend ostream& operator<<(ostream& os, Cone c);
	Cone operator++(int);
	Cone operator++();
};


#endif