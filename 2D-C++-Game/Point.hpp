#ifndef _POINT_HPP_
#define _POINT_HPP_
#include <cmath>

using std::abs;

class Point{
    double _x, _y;
public:
    Point() : _x{0}, _y{0}{}
    Point(double x, double y) : _x{x}, _y{y}{}
    double x(){return _x;}
    double y(){return _y;}
    Point absolute(){return Point(abs(_x),abs(_y));}

    Point operator+(const Point p){return Point(_x + p._x, _y + p._y);}
    Point operator-(const Point p){return Point(_x - p._x, _y - p._y);}
    Point& operator+=(const Point& p){_x += p._x; _y += p._y; return *this;}
    Point& operator-=(const Point& p){_x -= p._x; _y -= p._y; return *this;}
    Point& operator=(const Point p){_x = p._x; _y = p._y; return *this;}
    bool operator==(const Point p){return (_x == p._x && _y == p._y);}
    bool operator!=(const Point& p){return !(*this == p);}
};

#endif // _POINT_HPP_
