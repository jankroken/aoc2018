//
// Created by Jan Kroken on 2018-12-05.
//

#include <vector>
#include <string>
#include <list>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;

set<string> substrings(const string word) {
    set<string> result{};
    for (int i = 0; i < word.size(); i++) {
        string sub{word};
        sub.erase(i, 1);
        cout << " sub(2): " << sub << endl;
        result.insert(sub);
    }
    return result;
}

class DuplicateScanner {
private:
    set<string> values{};
public:
    bool seen(string value) {
        if (values.count(value) > 0) {
            return true;
        } else {
            values.insert(value);
            return false;
        }
    }
};

int main() {
    list<string> words{};
    ifstream input("input2.txt");
    string line;
    DuplicateScanner scanner{};

    while (getline(input, line)) {
        words.push_back(line);
    }

    for (const auto word: words) {
        cout << word << endl;
        auto subs = substrings(word);
        for (const auto sub: subs) {
            cout << " > " << sub << endl;
            if (scanner.seen(sub)) {
                cout << " Found duplicate: " << sub << endl;
            }
        }
    }
    return 0;
}