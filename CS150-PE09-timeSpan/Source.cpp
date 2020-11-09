#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "p1.h"
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v);

TimeSpan::TimeSpan()
{
    h_ = 0;
    m_ = 0;
}
TimeSpan::TimeSpan(double h, double m) { h_ = h; m_ = m; }
double TimeSpan::hours() const
{
    return h_;
}
double TimeSpan::minutes() const
{
    return m_;
}
double TimeSpan::hourspan() const
{
    double result = h_ + (m_ / 60);
    return result;
}

string TimeSpan::toString() const
{
    ostringstream out;
    out << h_ << ":" << m_;

    return out.str();
}

bool TimeSpan::operator<(const TimeSpan& ts2) const
{
    return h_ < ts2.h_&& m_ < ts2.m_;
}

ostream& operator<<(ostream& os, TimeSpan t)
{
    os << "{" << t.hours() << "," << t.minutes() << "}";
    return os;
}




int main()
{
    cout << "Exercising the TimeSpan class" << endl;
    cout << string(50, '-') << endl;

    TimeSpan t1{ 3, 45 };
    cout << "t1->" << t1 << endl;
    cout << "t1.hours()->" << t1.hours() << " == 3" << endl;
    cout << "t1.minutes()->" << t1.minutes() << " == 45" << endl;
    cout << "t1.hourspan()->" << t1.hourspan() << " == 3.75" << endl;
    cout << "t1.toString()->" << t1.toString() << " == 3:45" << endl;

    TimeSpan t2{ 0, 51 };
    cout << "t2->" << t2 << endl;
    cout << "t2.hours()->" << t2.hours() << " == 0" << endl;
    cout << "t2.minutes()->" << t2.minutes() << " == 51" << endl;
    cout << boolalpha;
    cout << "t1 < t2 ? " << (t1 < t2) << " == false" << endl;

    vector<TimeSpan> v = { {12, 25}, {3, 97}, {0, 242} };
    cout << "Before, v->" << v << endl;
    sort(v.begin(), v.end());
    cout << "After, v->" << v << endl;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
    out << "[";
    if (v.size())
    {
        out << v[0];
        for (size_t i = 1, len = v.size(); i < len; i++)
            out << ", " << v[i];
    }
    out << "]";
    return out;
}
