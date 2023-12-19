// FIND DUPLICATE

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

// vector<int> findDuplicates(const vector<int> &nums) {
//     unordered_map<int, int> tes {};
//     vector<int> ans {};

//     for (auto &i : nums) {
//         if (tes.find(i) == tes.end()) {
//             tes.insert({i, 1});
//         } else {
//             // tes[i] += 1;
//             ans.push_back(i);
//         }
//     }
//     return ans;
// }

vector<int> findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> numCounts {};
    vector<int> duplicates {};

    for (int num : nums) {
        if (++numCounts[num] == 2) {
            duplicates.push_back(num);
        }
    }

    return duplicates;
}



int main() {
    cout << boolalpha << endl;

    vector<int> nums {1, 2, 3, 4, 4, 5, 5, 6, 7, 8};

    vector<int> answer = findDuplicates(nums);
    cout << "[ ";
    for (auto &i : answer) {
        cout << i << " ";
    }
    cout << "]" << endl;



    cout << "\n" << endl;
    return 0;
}