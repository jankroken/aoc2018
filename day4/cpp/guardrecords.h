//
// Created by Jan Kroken on 2018-12-19.
//

#ifndef CPP_GUARDRECORDS_H
#define CPP_GUARDRECORDS_H

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <regex>
#include <optional>

using namespace std;


enum class RecordType {
    START,
    SLEEP,
    WAKE
};

class GuardRecord {
public:
    const string dateTime;
    const RecordType type;
    const optional<int> guardId;
    const int minute;

    GuardRecord(const string &dateTime, const RecordType &type, const optional<int> guardId,
                const int minute) :
            dateTime{dateTime}, type{type}, guardId{guardId}, minute{minute} {};
};

std::ostream &operator<<(std::ostream &os, const GuardRecord &record);

class GuardRecords {
private:
    const string filename;
public:
    GuardRecords(string filename) : filename{filename} {};

    list<GuardRecord> read() const;
};

#endif //CPP_GUARDRECORDS_H
