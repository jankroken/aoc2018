//
// Created by Jan Kroken on 2018-12-05.
//

#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    list<string> words {};
    ifstream input("input2.txt");
    string line;

    while (getline(input,line)) {
        words.push_back(line);
    }

    for (auto l: words) cout << l << endl;

    return 0;
}