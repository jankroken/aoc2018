#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>

using namespace std;

class IntSource {
private:
    ifstream *input;
    const string &fname;
    bool no_input{true};
    const int max_count;
    int current_count{0};

    ifstream *get_stream() {
        if (no_input) {
            if (input->is_open()) input->close();
            cout << "Opening file: " + fname << endl;
            input = new ifstream(fname);
            no_input = false;
        }
        return input;
    }

public:
    IntSource(const string &filename, int max) : fname{filename}, no_input(true), max_count{max} {};

    int next() {
        int value;
        ifstream *input = get_stream();
        if ((*input) >> value) {
            current_count++;
            return value;
        } else {
            no_input = true;
            return next();
        }
    }

    bool hasNext() {
//        cout << "current_count=" << current_count << " max_count=" << max_count << endl;
        return current_count < max_count;
    }
};

class UniqueDetector {
private:
    set<int> values{};
public:
    UniqueDetector() {}

    bool isUnique(int value) {
        if (values.count(value) > 0) {
            return false;
        } else {
            cout << "Adding new unique value: " << value << endl;
            values.insert(value);
            return true;
        }
    }
};

int main() {
    auto source = new IntSource("input.txt", 500000);
    auto uniques = new UniqueDetector();
    int value;
    int acc{0};

    readLoop:
    while (source->hasNext()) {
        value = source->next();
        // cout << "read value" << value << endl;
        acc += value;
        if (!(uniques->isUnique(acc))) {
            cout << "Found duplicate accumulated value: " << acc << endl;
            break;
        }
    }

    cout << "Accumulated: " << acc << std::endl;
    return 0;
}