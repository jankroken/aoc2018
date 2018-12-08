#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <regex>

using namespace std;

class Claim {
public:
    const int id;
    const int x;
    const int x2;
    const int y;
    const int y2;
    const int width;
    const int height;

    Claim(int id, int x, int y, int height, int width) : id(id), x(x), y(y), width(width), height(height),
                                                         x2{x + width}, y2{y + height} {}
};

std::ostream &operator<<(std::ostream &os, Claim const &c) {
    return os << "Claim(id=" << c.id << " pos=" << c.x << "," << c.y << " size=" << c.width << "x" << c.height << ")";
}

const regex lineexpr = regex("^#([0-9]+) @ ([0-9]+),([0-9]+): ([0-9]+)x([0-9]+)$");

Claim parse(const string& line) {
    smatch matches;
    if (regex_search(line, matches, lineexpr)) {
        return Claim(stoi(matches[1].str()), stoi(matches[2].str()), stoi(matches[3].str()), stoi(matches[4].str()), stoi(matches[5].str()));
    } else {
        cout << "not matching" << endl;
        throw invalid_argument("Not matching: "+line);
    }
}

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
    const auto claims = readClaims("input3.txt");
    for (const auto claim: claims) {
        cout << claim << endl;
    }
    return 0;
}