#include <iostream>
#include <fstream>
#include <map>

using namespace std;

template <class T>
class Counter {
private:
    map<T, int> letterMap{};
public:
    void add(const T key) {
        cout << "adding " << key << endl << " count=" << letterMap.count(key) << endl;
        if (letterMap.count(key) == 0) {
            letterMap.insert(make_pair(key, 1));
        } else {
            int count = letterMap.at(key);
            cout << "adding existing(" << key << ") count=" << count << endl;
            letterMap.erase(key);
            letterMap.insert(make_pair(key, count + 1));
        }
    }

    bool got_count(const int count) {
        for (pair<T,int> entry : letterMap) {
            cout << "got_count(" << count << ") pair<" << entry.first << "," << entry.second << ">" << endl;
            if (entry.second == count) return true;
        }
        return false;
    }
    int get_count(const T key) {
        if (letterMap.count(key) > 0) {
            return letterMap.at(key);
        } else {
            return 0;
        }
    }
};


int main() {

    Counter<int> wordSizeCounter {};

    string line;


    ifstream inputFile("input2.txt");
    while (getline(inputFile,line)) {
        Counter<char> characterCounter {};
        for (char c: line) {
            characterCounter.add(c);
        }
        if (characterCounter.got_count(2)) wordSizeCounter.add(2);
        if (characterCounter.got_count(3)) wordSizeCounter.add(3);
    }

    auto twos = wordSizeCounter.get_count(2);
    auto threes = wordSizeCounter.get_count(3);

    cout << " twos=" << twos << " threes=" << threes << " hash(*)=" << (twos * threes) << endl;
    return 0;
}