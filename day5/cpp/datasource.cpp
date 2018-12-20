#include "datasource.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string read(string file) {
    ifstream input(file);
    string line;
    getline(input, line);
    return line;
}