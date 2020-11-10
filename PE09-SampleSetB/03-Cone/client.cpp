#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "p1.h"
Cone::Cone() { r_ = 0; h_ = 0; }
Cone::Cone(double r, double h) { r_ = r; h_ = h; }
double Cone::radius() const { return r_; }
double Cone::height() const { return h_; }
double Cone::volume() const { return PI * pow(r_,2) * (h_ / 3); }
double Cone::area() const { return PI * r_ * (r_ + sqrt(pow(h_, 2) + pow(r_, 2))); }
Cone Cone::operator++(int i)
{
    h_++;
    return *this;
}

Cone Cone::operator++()
{
    ++r_;
    return *this;
}

ostream& operator<< (ostream& os, Cone c)
{
    os << "Cone(r->" << c.radius() << ", h->" << c.height() << ", volume->" << c.volume() << ", area->" << c.area() << ")";

    return os;
}

int main()
{
    cout << "Exercising the Cone class" << endl;
    cout << string(50, '-') << endl;
    cout << fixed << setprecision(2);
    double r = 4.28;
    double h = 3.16;

    Cone c1{r, h};
    cout << "c1.radius()->" << c1.radius() << " == " << r << endl;
    cout << "c1.height()->" << c1.height() << " == " << h << endl;
    // Volume
    cout << "c1.volume()->" << c1.volume() << " == 60.62" << endl;
    // Total surface area
    cout << "c1.area()->" << c1.area() << " == 129.08" << endl;

    cout << "c1->" << c1 << endl;
    auto original = c1++;       // post-increment height
    cout << "c1++->" << original << endl;
    cout << "c1->" << c1 << endl;
    cout << "++c1->" << ++c1 << endl;   // pre-increment radius
    cout << "c1.volume()->" << c1.volume() << " == 121.45" << endl;
    cout << "c1.area()->" << c1.area() << " == 199.08" << endl;

}
