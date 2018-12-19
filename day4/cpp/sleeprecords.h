//
// Created by Jan Kroken on 2018-12-19.
//

#include <list>
#include <string>
#include "guardrecords.h"
#ifndef CPP_SLEEPRECORDS_H
#define CPP_SLEEPRECORDS_H

bool compare(const GuardRecord& first, const GuardRecord& second);

class SleepRecord {
public:
    const int guardId;
    const int start;
    const int end;
    SleepRecord(int guardId, int start, int end): guardId{guardId}, start{start}, end{end} {}
    inline int minutes() const {
        return end - start + 1;
    }
};

std::ostream &operator<<(std::ostream &os, const SleepRecord &record);

class SleepRecordBuilder {
private:
    list<GuardRecord> guardRecords;
public:
    SleepRecordBuilder(list<GuardRecord> records);
    list<GuardRecord> getGuardRecords() {
        return guardRecords;
    }
    list<SleepRecord> build();
};

list<SleepRecord> forGuard(list<SleepRecord> sleeps, int guardId);

#endif // CPP_SLEEPRECORDS_H

