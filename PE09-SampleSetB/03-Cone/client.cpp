#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "p1.h"

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
