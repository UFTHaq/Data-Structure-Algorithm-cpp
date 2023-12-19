// ITEM IN COMMON OR SAME INT IN 2 VECTOR

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

bool itemInCommon(vector<int> &vec1, vector<int> &vec2) {
    unordered_map<int, bool> myMap {};

    for (auto &i : vec1) {
        myMap.insert({i, true});
    }

    for (auto &j : vec2) {
        if (myMap[j]) return true;
    }

    return false;
}

int main() {
    cout << boolalpha << endl;

    vector<int> a {1,3,5};
    vector<int> b {2,4,5};

    cout << "Is there the same number: " << itemInCommon(a, b);

    cout << "\n" << endl;
    return 0;
}