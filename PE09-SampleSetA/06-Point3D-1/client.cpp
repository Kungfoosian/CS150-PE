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

    Point3D p1;
    cout << "p1.x()->" << p1.x() << endl;
    cout << "p1.y()->" << p1.y() << endl;
    cout << "p1.z()->" << p1.z() << endl;
    cout << "p1->" << p1 << endl;
    cout << "Expected: Point3D(0.0, 0.0, 0.0)" << endl;

    Point3D p2{2.5, 1.7, 9.3};
    cout << "p2.x()->" << p2.x() << endl;
    cout << "p2.y()->" << p2.y() << endl;
    cout << "p2.z()->" << p2.z() << endl;
    cout << "p2->" << p2 << endl;
    cout << "Expected: Point3D(2.5, 1.7, 9.3)" << endl;

    cout << "(p1 - p2)->" << (p1 - p2) << endl;
    cout << " Expected: 9.8" << endl;
}
