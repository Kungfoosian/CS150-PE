#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "p1.h"
Sphere::Sphere(double r) { r_ = r; }
double Sphere::radius() const { return r_; }
double Sphere::volume() const {return 4 / 3 * PI * pow(r_, 3);}
double Sphere::area() const { return 4 * PI * pow(r_, 2); }
string Sphere::toString() const
{
	ostringstream oss;
	oss << "Sphere(radius->" << r_ << ", volume->" << volume() << ", area->" << area() << ")";
	return oss.str();
}
Sphere Sphere::operator* (double d)
{
	Sphere result;
	result.r_ = r_ * d;
	return result;
}
void Sphere::operator/=(double d)
{
	r_ /= d;
}


int main()
{
	cout << "Exercising the Sphere class" << endl;
	cout << string(50, '-') << endl;
	cout << fixed << setprecision(2);

	double r = 3.56;
	Sphere s1{ r };
	cout << "s1.radius()->" << s1.radius() << " == 3.56" << endl;
	cout << "s1.volume()->" << s1.volume() << " == 188.99" << endl;
	cout << "s1.area()->" << s1.area() << " == 159.26" << endl;
	cout << "s1.toString()->" << s1.toString() << endl;

	auto s2 = s1 * .5;  // scale by .5
	cout << "After s2 = s1 * .5; s2.toString()->" << s2.toString() << endl;
	cout << "After s2 = s1 * .5; s2.radius()->" << s2.radius() << endl;

	s2 /= .5;   // divide by .5
	cout << "After s2 /= .5; s2.toString()->" << s2.toString() << endl;
	cout << "After s2 /= .5; s2.radius()->" << s2.radius() << endl;

}
