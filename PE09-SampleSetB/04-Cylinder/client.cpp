#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

#include "p1.h"

Cylinder::Cylinder() { r_ = 0; h_ = 0; }
Cylinder::Cylinder(double r, double h) { r_ = r; h_ = h; }
double Cylinder::radius() const { return r_; }
double Cylinder::height() const { return h_; }
double Cylinder::volume() const { return PI * pow(r_, 2) * h_; }
double Cylinder::area() const { return 2 * PI * r_ * h_ + 2 * PI * pow(r_, 2); }
ostream& operator<<(ostream& os, Cylinder c)
{
    os << "Cylinder(radius->" << c.radius() << ", height->" << c.height() << ", volume->" << c.volume() << ", area->" << c.area() << ")";
    return os;
}
Cylinder Cylinder::operator~()
{
    return Cylinder{h_, r_};
} // Invert radius -> height (vice versa), original stays the same
void Cylinder::operator!()
{
    r_ = 1 / r_;
    h_ = 1 / h_;
} // Flipping members?


int main()
{
    cout << "Exercising the Cylinder class" << endl;
    cout << string(50, '-') << endl;
    cout << fixed << setprecision(2);
    double r = 4.28;
    double h = 3.16;

    Cylinder c1{r, h};
    cout << "c1.radius()->" << c1.radius() << " == " << r << endl;
    cout << "c1.height()->" << c1.height() << " == " << h << endl;
    // Volume
    cout << "c1.volume()->" << c1.volume() << " == 181.85" << endl;
    // Total surface area
    cout << "c1.area()->" << c1.area() << " == 200.08" << endl;

    // Invert the cylinder (radius->height, height->radius; does not change c1)
    cout << "c1->" << c1 << endl;
    auto c2 = ~c1;
    cout << "c2 = ~c1; c1->" << c1 << endl;
    cout << "c2 = ~c1; c2->" << c2 << endl;

    Cylinder c3(1, 3);
    cout << "c3->" << c3 << endl;
    // Mutate by flipping members - changes c3
    !c3;
    cout << "!c3; c3->" << c3 << endl;

}
