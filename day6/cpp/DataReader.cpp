//
// Created by Jan Kroken on 2018-12-22.
//

#include "DataReader.h"

#include <string>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

DataReader::DataReader(const string& filename): filename{filename} {}

list<Point> DataReader::read() {
    list<Point> result;
    const regex re("^([0-9]*), *([0-9]*)$");
    smatch match;
    ifstream input{filename};
    string line;
    while (getline(input, line)) {
//        cout << line << endl;
        if (regex_search(line, match, re)) {
            Point point{stoi(match[1]),stoi(match[2])};
            cout << (point) << endl;
            result.push_back(point);
        }
    }
    return result;
}

bool isBounded(Point p, list<Point> l) {
    bool boundedEast = false;
    bool boundedWest = false;
    bool boundedNorth = false;
    bool boundedSouth = false;
    for (auto other: l) {
        if (other == p) {
            continue;
        } else {
            int dx = other.x - p.x;
            int dy = other.y - p.y;
            if (dx > 0 && abs(dy) <= dx) { boundedEast = true; p.eastBound = other.x; }
            if (dx < 0 && abs(dy) <= -dx) { boundedWest = true; p.westBound = other.x; }
            if (dy > 0 && abs(dx) <= dy) { boundedSouth = true; p.southBound = other.y; }
            if (dy < 0 && abs(dx) <= -dy) { boundedNorth = true; p.northBound = other.y; }
        }
    }
    return boundedEast && boundedWest && boundedNorth && boundedSouth;
}

list<Point> findBounded(list<Point> points) {
    list<Point> result {};
    for (Point p: points) {
        if (isBounded(p, points)) {
            result.push_back(p);
        }
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "Point(" << point.x << "," << point.y << ")";
    return os;
}
