#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "p1.h"

int main()
{
    cout << "Exercising the Point3D class" << endl;
    cout << string(50, '-') << endl;
    cout << fixed << setprecision(1);

    Point3D p1{2.5, 1.7, 9.3};
    cout << "p1.x()->" << p1.x() << endl;
    cout << "p1.y()->" << p1.y() << endl;
    cout << "p1.z()->" << p1.z() << endl;
    cout << "p1->" << p1.toString() << endl;
    cout << "Expected: Point3D(2.5, 1.7, 9.3)" << endl;

    cout << "p1.magnitude()->" << p1.magnitude() << endl;
    cout << " Expected: 9.8" << endl;
    p1.normalize();
    cout << "After normalize->" << p1.magnitude() << endl;
}
