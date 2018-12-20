#include "shrinker.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>

using namespace std;

Shrinker::Shrinker(string input) {
    this->input = input;
    forwards = vector<int>(input.size());
    backs = vector<int>(input.size());
    start = 0;
    end = input.size();
    for (int i = 0; i < input.size()-1; i++) {
        forwards[i] = i+1;
        backs[i+1] = i;
    }
    forwards[input.size()-1] = -1;
    backs[0] = -1;
}

bool polars(char c1, char c2) {
//    cout << "polars(" << c1 << c2 << ")" << endl;
    return c1 != c2 && toupper(c1) == toupper(c2);
}


string Shrinker::shrink() {
    list<char> chars(input.begin(),input.end());
    cout << "rmunits() size " << chars.size() << endl;
    auto curr = chars.begin();
    auto next = chars.begin();
    next++;
    int counter = 0;
    while (next != chars.end()) {
//        cout << *curr << "," << *next << endl;
        if (polars(*curr,*next)) {
//            cout << "RM " << (*curr) << (*next) << endl;
            next = chars.erase(next);
            curr = chars.erase(curr);
            next = curr;
            next++;
            if (curr != chars.begin()) {
//                cout << "backstepping" << endl;
                curr--;
                next--;
            } else {
//                cout << "already at start" << endl;
            }
        } else {
            curr++;
            next++;
        }
    }
    stringstream result;
    for (char c: chars) {
        result << c;
    }

    return result.str();
}

string Shrinker::rmunits(char first, char second) {
    list<char> chars(input.begin(),input.end());
    auto curr = chars.begin();
    while (curr != chars.end()) {
        if (*curr == first || *curr == second) {
            curr = chars.erase(curr);
        } else {
            curr++;
        }
    }
    stringstream result;
    for (char c: chars) {
        result << c;
    }

    return result.str();
}