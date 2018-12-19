#include <iostream>
#include "guardrecords.h"
#include "sleeprecords.h"
#include <list>

int main() {
    GuardRecords records = GuardRecords("input4.txt");
    SleepRecordBuilder builder(records.read());
    auto sleeps = builder.build();

//    list<GuardRecord> recs = records.read();
    for (auto rec: sleeps) {
        cout << rec << endl;
    }
    return 0;
}