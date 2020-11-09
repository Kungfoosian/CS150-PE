#ifndef P1_H
#define P1_H
#include "point.h"

// Define your class here
class Circle
{
private:
	Point center_;
	double radius_;
public:
	Circle();
	Circle(Point, double);
	Point center() const;
	double radius() const;
	double area() const;
	double circumference() const;
	std::string toString() const;
	void translate(const Point& newPoint);
	Circle operator*(const double& d) const;
	friend ostream& operator<<(ostream& os, Circle c);

};



#endif