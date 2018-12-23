#include <iostream>
#include "DataReader.h"
#include <list>

int main() {
    std::cout << "Hello, World!" << std::endl;
    DataReader reader("input6ex.txt");
    auto points = reader.read();
    for (auto p : points) {
        if (isBounded(p, points)) {
            cout << p << " is bounded" << endl;
        } else {
            cout << p << " is unbounded" << endl;
        }

    }
    return 0;
}