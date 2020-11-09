#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "p1.h"

int main()
{
    cout << "Exercising the Sphere class" << endl;
    cout << string(50, '-') << endl;
    cout << fixed << setprecision(2);

    double r = 3.56;
    Sphere s1{r};
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
