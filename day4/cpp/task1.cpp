#include <iostream>
#include "guardrecords.h"
#include "sleeprecords.h"
#include "accumulators.h"
#include <list>

int main() {
    GuardRecords records = GuardRecords("input4.txt");
    SleepRecordBuilder builder(records.read());
    auto sleeps = builder.build();

    for (auto rec: sleeps) {
        cout << rec << endl;
    }

    auto minsByGuard = minutesAsleepByGuard(sleeps);

    for (auto entry: minsByGuard) {
        cout << "#" << entry.first << "=" << entry.second << endl;
    }
    int guardId = largestValue(minsByGuard).first;
    cout << "guard: " << guardId << " value=" << minsByGuard[guardId] << endl;

    map<int,int> countPerMinute = timesPerMinute(forGuard(sleeps, guardId));

    for(auto entry: countPerMinute) {
        cout << "min[" << entry.first << "] = " << entry.second << endl;
    }

    auto sleepiestMinute = largestValue(countPerMinute);
    cout << "Sleepiest minute: " << sleepiestMinute.first << ": " << sleepiestMinute.second << endl;

    cout << "The answer (guardId * sleepiest minute) = " << (guardId * sleepiestMinute.first) << endl;

    return 0;
}