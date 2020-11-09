#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "p1.h"

Circle::Circle() { center_ = Point{}; radius_ = 0; }
Circle::Circle(Point p, double d) { center_ = p; radius_ = d; }
Point  Circle::center() const { return center_; }
double Circle::radius() const { return radius_; }
double Circle::area() const { return PI * pow(radius_, 2); }
double Circle::circumference() const { return 2 * PI * radius_; }
string Circle::toString() const
{
    return center_.toString();
}
void Circle::translate(const Point& newPoint)
{
    Point temp{center_.x()+ newPoint.x(),center_.y()+newPoint.y()};
    center_ = temp;
}

Circle Circle::operator*(const double& d) const
{
    Circle result;
    result.center_ = center_;
    result.radius_ = radius_* d;

    return result;
}


ostream& operator<<(ostream& os, Circle c)
{
    os << "Circle(" << c.center_.toString() << ", " << c.radius() << ")";
    return os;
}

int main()
{
    cout << "Exercising the Circle class" << endl;
    cout << string(50, '-') << endl;
    cout << fixed << setprecision(1);

    Circle c1{ Point(5, 6), 15.2 };
    cout << "c1->" << c1 << endl;
    cout << "c1.center()->" << c1.center().toString() << " == Point(5, 6)" << endl;
    cout << "c1.radius()->" << c1.radius() << " == 15.2" << endl;
    cout << "c1.area()->" << c1.area() << " == 725.8" << endl;
    cout << "c1.circumference()->" << c1.circumference() << " == 95.5" << endl;
    cout << "c1.toString()->" << c1.toString() << endl;
    c1.translate(Point(-1, 2));
    cout << "After translate, c1: " << c1 << endl;
    cout << "           Expected: Circle(Point(4, 8), 15.2)" << endl;

    auto c2 = c1 * .5;
    cout << "After * .5, c2: " << c2 << endl;
    cout << "      Expected: Circle(Point(4, 8), 7.6)" << endl;


}
