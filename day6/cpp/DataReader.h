//
// Created by Jan Kroken on 2018-12-22.
//

#ifndef CPP_DATAREADER_H
#define CPP_DATAREADER_H

#include <string>
#include <list>

using namespace std;

class Point {
public:
    const int x,y;
    int eastBound, westBound, northBound, southBound;
    Point(int x, int y): x{x},y{y} {}
    inline bool operator==(Point p) const {
        return (x == p.x && y == p.y);
    }
    inline bool operator!=(Point p) const {
        return !(operator==(p));
    }
    inline int distance(const Point& p) const {
        return abs(x-p.x) + abs(y-p.y);
    }
    inline int distance(const int x2, const int y2) const {
        return abs(x-x2) + abs(y-y2);
    }
};


class DataReader {
private:
    const string filename;
public:
    DataReader(const string& filenames);
    list<Point> read() const;
};

std::ostream &operator<<(std::ostream &os, const Point &point);

bool isBounded(Point& p, const list<Point>& l);

list<Point> findBounded(const list<Point>& points);

#endif //CPP_DATAREADER_H
