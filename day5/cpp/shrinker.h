#ifndef CPP_SHRINKER_H
#define CPP_SHRINKER_H

#include <string>
#include <vector>

using namespace std;

class Shrinker {
private:
    string input;
    vector<int> forwards;
    vector<int> backs;
    int start;
    int end;
public:
    Shrinker(string input);
    string shrink();
    string rmunits(char first, char second);
};

#endif //CPP_SHRINKER_H



