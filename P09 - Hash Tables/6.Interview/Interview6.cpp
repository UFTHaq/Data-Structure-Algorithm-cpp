// SUB ARRAY SUM

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// vector<int> subarraySum(const vector<int> &nums, int target) {
//     vector<int> ans {};
//     int right {};
//     int left {};

//     int sum {};
//     for (int i = 0; i < nums.size(); i++) {
//         if (sum < target) {
//             sum += nums[i];
//             right = i;
//         } else if (sum == target) {
//             return {0, right};
//         }
//     }

//     for (int j = 0; j < nums.size(); j++) {
//         if (sum > target) {
//             sum -= nums[j];
//             left++;
//         } else if (sum == target) {
//             return {left, right};
//         }
//     }

//     return {INT_MIN};
// }

vector<int> subarraySum(const vector<int>& nums, int target) {
    unordered_map<int, int> sumIndex;
    sumIndex[0] = -1;
    int sum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sumIndex.find(sum - target) != sumIndex.end()) {
            return {sumIndex[sum - target] + 1, i};
        }
        sumIndex[sum] = i;
    }
    
    return {};
}

int main() {
    cout << boolalpha << endl;

    vector<int> nums {1,2,3,7,5};
    int target {12};
    // vector<int> nums {1,4,20,3,10,5};
    // int target {33};

    vector<int> answer = subarraySum(nums, target);
    for (auto &i : answer) {
        cout << i << " ";
    }


    cout << "\n" << endl;
    return 0;
}