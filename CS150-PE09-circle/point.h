#ifndef POINT_H
#define POINT_H
#include <string>
#include <cmath>
class Point {
public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) {}
    int x() const { return x_; }
    int y() const { return y_; }
    std::string toString() const {
        return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    }
private:
    int x_, y_;
};

const double PI = std::acos(-1);

#endif