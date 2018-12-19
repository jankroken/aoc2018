//
// Created by Jan Kroken on 2018-12-19.
//

#ifndef CPP_ACCUMULATORS_H
#define CPP_ACCUMULATORS_H

#include <map>
#include "sleeprecords.h"

using namespace std;

map<int,int> minutesAsleepByGuard(list<SleepRecord> records);

pair<int,int> largestValue(map<int,int> valueMap);

map<int,int> timesPerMinute(list<SleepRecord> records);

#endif //CPP_ACCUMULATORS_H
