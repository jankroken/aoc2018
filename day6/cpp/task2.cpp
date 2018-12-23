#include <iostream>
#include "DataReader.h"
#include "AreaCalculator.h"
#include <list>

int totalDist(const int x, const int y, const list<Point> &points) {
    int sum = 0;
    for (auto p: points) {
        sum += p.distance(x, y);
    }
    return sum;
}

int main() {
    DataReader reader("input6.txt");
    auto points = reader.read();
    int minx, maxx, miny, maxy;
    minx = maxx = points.front().x;
    miny = maxy = points.front().y;
    int safe = 0;
    for (auto p: points) {
        if (miny > p.y) miny = p.y;
        if (maxy < p.y) maxy = p.y;
        if (minx > p.x) minx = p.x;
        if (maxx < p.x) maxx = p.x;
    }
    cout << "squares to check: " << ((maxy - miny + 1) * (maxx - minx + 1)) << endl;
    for (int x = minx; x <= maxx; x++) {
        for (int y = miny; y <= maxy; y++) {
            if (totalDist(x, y, points) < 10000) {
                safe++;
            }
        }
    }
    cout << "safe: " << safe << endl;
    return 0;
}