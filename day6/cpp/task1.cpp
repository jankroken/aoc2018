#include <iostream>
#include "DataReader.h"
#include "AreaCalculator.h"
#include <list>

int main() {
    DataReader reader("input6.txt");
    auto points = reader.read();
    auto bounded = findBounded(points);
    int largestArea = 0;
    for (auto p : points) {
        if (isBounded(p, points)) {
            cout << p << " is bounded" << endl;
            AreaCalculator areaCalculator(p , points);
            int area = areaCalculator.area();
            cout << "area=" << area << endl;
            if (area > largestArea) {
                largestArea = area;
            }
        } else {
            cout << p << " is unbounded" << endl;
        }

    }
    cout << "Largest area: " << largestArea << endl;
//    cout << " for " << largestPoint << endl;

    return 0;
}