#include <iostream>
#include "datasource.h"
#include "shrinker.h"

string without_poly(string s, char first, char second) {
    Shrinker polysh{s};
    string s1 = polysh.rmunits(first, second);
    Shrinker sh{s1};
    auto res = sh.shrink();
    cout << "without_poly: " << s.size() << " => " << s1.size() << " => " << res.size() << endl;
    return res;
}

int main() {
    string s = read("input5.txt");
    Shrinker sh{s};
    string res = sh.shrink();
    cout << "RESULT: " << res << endl
         << "length; " << res.size() << endl;


    char first = 'a';
    char second = 'A';

    int smallest = 100000000;

    while (first <= 'z') {
        string res = without_poly(s,first,second);
//        cout << first << second << " => " << res.size() << endl;
        if (res.size() < smallest) smallest = res.size();
         first++;
         second++;
    }

    cout << "smallest = " << smallest << endl;

    return 0;
}