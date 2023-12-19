// TWO SUMS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<int> twoSum(const vector<int> &nums, int target) {
    unordered_map<int, int> numIndices {};

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numIndices.find(complement) != numIndices.end()) {
            return {numIndices[complement], i};
        }

        numIndices[nums[i]] = i;
    }

    return {};
}

int main() {
    cout << boolalpha << endl;

    vector<int> nums {1,3,4,2,5};
    int target {6};

    vector<int> ans = twoSum(nums, target);
    for (auto &i: ans) {
        cout << i << " ";
    }

    cout << "\n" << endl;
    return 0;
}