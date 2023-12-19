// HAS UNIQUE CHAR

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool hasUniqueChar(const string &str) {
    unordered_set<char> charSet {};

    for (auto &c : str) {
        if (charSet.find(c) != charSet.end()) {
            return false;
        }
        charSet.insert(c);
    }
    return true;
}

int main() {
    cout << boolalpha << endl;

    vector<string> str {"hello", "world"};

    for (auto &i : str) {
        cout << i << ": " << hasUniqueChar(i) << "\n";
    }

    cout << endl;
    return 0;
}