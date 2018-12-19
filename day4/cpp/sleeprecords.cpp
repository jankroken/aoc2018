//
// Created by Jan Kroken on 2018-12-19.
//

#include <list>
#include <string>
#include "guardrecords.h"
#include "sleeprecords.h"

bool compare(const GuardRecord& first, const GuardRecord& second) {
    return first.dateTime < second.dateTime;
}


SleepRecordBuilder::SleepRecordBuilder(list<GuardRecord> records): guardRecords{records} {
    guardRecords.sort(compare);
//    guardRecords = records;
}

list<SleepRecord> SleepRecordBuilder::build() {

    list<SleepRecord> results{};

    int guardId = -1;
    int start = -1;
    int end;

    for (auto rec: guardRecords) {
        switch(rec.type) {
            case RecordType::START:
                guardId = rec.guardId.value();
                break;
            case RecordType::SLEEP:
                start = rec.minute;
                break;
            case RecordType::WAKE:
                end = rec.minute;
                results.push_back(SleepRecord(guardId,start,end));
                start = -1;
                break;
        }
    }
    return results;
}

std::ostream &operator<<(std::ostream &os, const SleepRecord &record) {
    os << "SleepRecord(guard=" << record.guardId << ",[" << record.start << "," << record.end << "])";
    return os;
};