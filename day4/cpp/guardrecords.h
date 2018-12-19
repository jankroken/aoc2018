//
// Created by Jan Kroken on 2018-12-19.
//

#ifndef CPP_GUARDRECORDS_H
#define CPP_GUARDRECORDS_H
#endif //CPP_GUARDRECORDS_H

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <regex>

using namespace std;


enum class RecordType {
    START,
    SLEEP,
    WAKE
};

class GuardRecord {
public:
    const RecordType type;
    int guardId;
    int minute;
};

class GuardRecords {
private:
    const regex re = regex("^\\[([0-9]*) .*$ ");
    GuardRecord toRecord(string line) {
        cout << "line" << endl;
        return GuardRecord{};
    };
public:
    GuardRecords(string filename) {
        ifstream input(filename);
        string line;
        while(getline(input, line)) {
            toRecord(line);
        }
    }
};