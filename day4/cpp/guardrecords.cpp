//
// Created by Jan Kroken on 2018-12-19.
//

#include "guardrecords.h"

using namespace std;

const regex re = regex("^\\[([0-9]*)-([0-9]*)-([0-9]*) ([0-9]*):([0-9]*)\\] ([A-Za-z]*) ([#0-9A-Za-z]*).*");


RecordType recordType(const string &str) {
    if ("Guard" == str) return RecordType::START;
    if ("falls" == str) return RecordType::SLEEP;
    if ("wakes" == str) return RecordType::WAKE;
    throw invalid_argument(str);
}

std::ostream &operator<<(std::ostream &os, const RecordType &type) {
    switch (type) {
        case RecordType::START:
            os << "START";
            break;
        case RecordType::WAKE:
            os << "WAKE";
            break;
        case RecordType::SLEEP:
            os << "SLEEP";
            break;
    }
    return os;
};

GuardRecord toRecord(string line) {
    smatch match;
    if (regex_search(line, match, re)) {
        string dateTime = line.substr(0,18);
        cout << dateTime << endl;
        int minute = stoi(match[5]);
        RecordType type = recordType(match[6]);
        switch (type) {
            case RecordType::START:
                return GuardRecord{dateTime, RecordType::START, stoi(match[7].str().substr(1)), minute};
            case RecordType::SLEEP:
                return GuardRecord{dateTime, RecordType::SLEEP, {}, minute};
            case RecordType::WAKE:
                return GuardRecord{dateTime, RecordType::WAKE, {}, minute};
        }
    } else {
        throw invalid_argument(line);
    }
};

std::ostream &operator<<(std::ostream &os, const GuardRecord &record) {
    string secondArg = record.guardId.has_value() ? to_string(record.guardId.value()) : "-";
    os << "GuardRecord(" << record.dateTime << "," << record.type << "," << secondArg << "," << record.minute << ")";
    return os;
};

list<GuardRecord> GuardRecords::read() {
    list<GuardRecord> records{};
    ifstream input(filename);
    string line;
    while (getline(input, line)) {
        auto record = toRecord(line);
//        cout << record << endl;
        records.push_back(record);
    }
    return records;
}

