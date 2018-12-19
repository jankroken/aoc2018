#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <regex>
#include <set>

using namespace std;

class Claim {
public:
    const int id;
    const int x;
    const int y;
    const int width;
    const int height;
    typedef pair<int, int> point;

    Claim(int id, int x, int y, int height, int width) : id(id), x(x), y(y), width(width), height(height) {};

    list<point> getAllSquares() {
        list<point> result{};
        for (int dx = 0; dx < width; dx++) {
            for (int dy = 0; dy < height; dy++) {
                result.push_back(pair(x + dx, y + dy));
            }
        }
        return result;
    }
};

std::ostream &operator<<(std::ostream &os, Claim const &c) {
    return os << "Claim(id=" << c.id << " pos=" << c.x << "," << c.y << " size=" << c.width << "x" << c.height << ")";
}

const regex lineexpr = regex("^#([0-9]+) @ ([0-9]+),([0-9]+): ([0-9]+)x([0-9]+)$");

Claim parse(const string &line) {
    smatch matches;
    if (regex_search(line, matches, lineexpr)) {
        return Claim(stoi(matches[1].str()), stoi(matches[2].str()), stoi(matches[3].str()), stoi(matches[4].str()),
                     stoi(matches[5].str()));
    } else {
        cout << "not matching" << endl;
        throw invalid_argument("Not matching: " + line);
    }
}

class OverlapTracker {
private:
    set<pair<int, int>> seen{};
    set<pair<int, int>> seenMultiple{};
public:
    void add(int x, int y) {
        if (seen.count(pair(x, y)) > 0) {
            cout << "> duplicate: " << x << "," << y << endl;
            seenMultiple.insert(pair(x, y));
        } else {
            cout << "> inserting regular: " << x << "," << y << endl;
            seen.insert(pair(x, y));
        }
    }

    int numberOfMultiples() {
        return seenMultiple.size();
    }
};

list<Claim> readClaims(string filename) {
    list<Claim> result{};
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        result.push_back(parse(line));
    }
    return result;
}

int main() {
    auto claims = readClaims("input3.txt");
    OverlapTracker tracker{};
    for (auto claim: claims) {
        cout << claim << endl;
        for (auto square: claim.getAllSquares()) {
            tracker.add(square.first, square.second);
        }
    }
    cout << "conflicting squares: " << tracker.numberOfMultiples() << endl;
    return 0;
}