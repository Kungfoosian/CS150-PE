#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "p1.h"

int main()
{
    cout << "Exercising the Day class" << endl;
    cout << string(50, '-') << endl;
    cout << fixed << setprecision(2);

    cout << "Print the days of the week" << endl;
    for (int i = 0; i < 6; i++)
        cout << "  " << i << ". " << Day(i) << endl;

    cout << "\n+= operator (by 2)..." << endl;
    Day d1(0);
    do {
        cout << (d1 += 2) << " ";
    } while (d1.toString() != "Sunday");
    cout << "\nExpect: Tuesday Thursday Saturday Monday Wednesday Friday Sunday" << endl;

    cout << "\n-= operator (by 1)..." << endl;
    Day d2(0);
    do {
        cout << (d2 -= 1) << " ";
    } while (d2.toString() != "Sunday");
    cout << "\nExpect: Saturday Friday Thursday Wednesday Tuesday Monday Sunday" << endl;

    cout << "\nInvalid constructors..." << endl;
    try {
        Day d3(-1);
        cout << "  XXX Error. Should not work." << endl;
    } catch (invalid_argument& e) {
        cout << "  + Day(-1) throws exception..." << endl;
    }
    try {
        Day d3(7);
        cout << "  XXX Error. Should not work." << endl;
    } catch (invalid_argument& e) {
        cout << "  + Day(7) throws exception..." << endl;
    }
    try {
        Day d3("mox");
        cout << "  XXX Error. Should not work." << endl;
    } catch (invalid_argument& e) {
        cout << "  + Day(\"mox\") throws exception..." << endl;
    }

    cout << "\nSome string conversions..." << endl;
    const char * days[] = {"Monday", "TUES", "weDnes", "THurs", "fRiX", "SATURN", "suNNY"};
    try {
        for (int i = 0; i < 7; i++)
            cout << "  + Day(\"" << days[i] << "\")->" << Day(days[i]) << endl;
    } catch (invalid_argument& e) {
        cout << "  XXX Error. " << e.what() << endl;
    }

}
