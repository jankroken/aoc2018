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
    auto guards = keys(minsByGuard);

    map<int, pair<int,int>> busyMinutes{};

    for (int guard: guards) {
        map<int,int> countPerMinute = timesPerMinute(forGuard(sleeps, guard));
        auto sleepiestMinute = largestValue(countPerMinute);
        busyMinutes[guard] = sleepiestMinute;
    }


    pair<int, pair<int,int>> solution{-1,{-1,-1}};
    for (int guard: guards) {
        if (busyMinutes[guard].second > solution.second.second) {
            cout << "NEW guard #" << guard << ": min=" << busyMinutes[guard].first << ": " << busyMinutes[guard].second << endl;
            solution = pair(guard,busyMinutes[guard]);
        }
    }

    cout << "Solution : guard= #" << solution.first << " minute=" << solution.second.first << ": " << solution.second.second << endl;
    cout << "           (guard * minute) " << (solution.first * solution.second.first) << endl;


    return 0;
}