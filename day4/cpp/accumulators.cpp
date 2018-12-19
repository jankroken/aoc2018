#include "accumulators.h"

#include <set>
#include <list>
#include "sleeprecords.h"

using namespace std;

map<int,int> minutesAsleepByGuard(list<SleepRecord> records) {
    map<int, int> result{};

    for (auto rec: records) {
        auto it = result.find(rec.guardId);
        if (it != result.end()) {
            int newValue = it->second + rec.minutes();
            result.erase(it);
            result[rec.guardId] = newValue;
        } else {
            result[rec.guardId] = rec.minutes();
        }
    }
    return result;
}

pair<int,int> largestValue(map<int,int> valueMap) {
    pair<int,int> result = pair(-1,-1);

    for (auto entry: valueMap) {
        if (entry.second > result.second) {
            result = entry;
        }
    }
    return result;
}

map<int,int> timesPerMinute(list<SleepRecord> records) {
    map<int,int> result;
    for(auto record: records) {
        for (int min = record.start; min < record.end; min++) {
            auto it = result.find(min);
            if (it != result.end()) {
                it->second += 1;
            } else {
                result[min] = 1;
            }
        }
    }
    return result;
}

list<int> keys(map<int,int> m) {
    list<int> result{};
    for (auto entry: m) {
        result.push_back(entry.first);
    }
    return result;
}


