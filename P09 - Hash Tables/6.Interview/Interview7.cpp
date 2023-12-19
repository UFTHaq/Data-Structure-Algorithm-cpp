// REMOVE DUPLICATE

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<int> removeDuplicates(const vector<int> &myList) {
    unordered_set<int> mySet {};

    for (auto &i : myList) {
        mySet.insert(i);
    }

    vector<int> ans {mySet.begin(), mySet.end()};

    return ans;
}

int main() {
    cout << boolalpha << endl;

    vector<int> myList {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};

    vector<int> answer = removeDuplicates(myList);
    for (auto &i : answer) {
        cout << i << " ";
    }


    cout << "\n" << endl;
    return 0;
}