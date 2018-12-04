#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    int value;
    int acc {0};

    if (input) {
        cout << "Missing input file" << endl;
    }

    while (input >> value) {
        cout << "read value" << value << endl;
        acc += value;
    }

    cout << "Accumulated: " << acc << std::endl;
    return 0;
}