// FIND PAIRS

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<vector<int>> findPairs(vector<int> &arr1, vector<int> &arr2, int target) {
    vector<vector<int>> answer {};
    unordered_set<int> mySet {};
    vector<int> temp_pairs {};

    for (auto &i : arr1) {
        mySet.insert(i);
    }

    for (auto &j : arr2) {
        int complement = target - j;
        if (mySet.find(complement) != mySet.end()) {
            temp_pairs.push_back(complement);
            temp_pairs.push_back(j);
            answer.push_back(temp_pairs);
            temp_pairs.clear();
        }
    }

    return answer;
}

// CARA LAIN
// vector<vector<int>> findPairs(vector<int> &arr1, vector<int> &arr2, int target) {
//     unordered_set<int> mySet;
//     vector<vector<int>> pairs;
 
//     for (int num : arr1) {
//         mySet.insert(num);
//     }
 
//     for (int num : arr2) {
//         int complement = target - num;
//         if (mySet.find(complement) != mySet.end()) {
//             pairs.push_back({complement, num});
//         }
//     }
 
//     return pairs;
// }

int main() {
    cout << boolalpha << endl;

    vector<int> vec1 {1,2,3};
    vector<int> vec2 {4,5,6};
    int target {8};

    vector<vector<int>> answer = findPairs(vec1, vec2, target);
    cout << "[ ";
    for (auto &i : answer) {
        cout << "( ";
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << ") ";
    } cout << "]";

    cout << endl;
    return 0;
}