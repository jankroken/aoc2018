//
// Created by Jan Kroken on 2018-12-19.
//

#include "guardrecords.h"

using namespace std;


const regex re = regex("^\\[([0-9]*)-([0-9]*)-([0-9]*) ([0-9]*):([0-9]*)\\] ([A-Za-z]*) ([#0-9A-Za-z]*).*");

GuardRecord toRecord(string line) {
    cout << line << endl;
    smatch match;
    if (regex_search(line, match, re)) {
        cout << "date: " << match[1] << "-" << match[2] << "-" << match[3] << endl;
        cout << "time: " << match[4] << ":" << match[5] << endl;
        cout << "command: " << match[6] << " param=" << match[7] << endl;
    } else {
        cout << "No match: " << line << endl;
    }

    return GuardRecord{};
};

GuardRecords::GuardRecords(string filename) {
    ifstream input(filename);
    string line;
    while (getline(input, line)) {
        toRecord(line);
    }
}
