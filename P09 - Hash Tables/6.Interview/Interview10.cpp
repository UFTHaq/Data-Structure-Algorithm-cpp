// LONGEST CONSECUTIVE SEQUENCE

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int longestConsecutiveSequence(const vector<int> &nums) {
    vector<int> ans = nums;
    int consecutive {};
    std::sort(ans.begin(), ans.end());
    
    int left {};
    for (auto &num : ans) {
        cout << num << " ";
        int selisih = num - left;
        if (selisih == 1) {
            consecutive++;
        } else {
            consecutive = 1;
        }
        left = num;
    }
    cout << endl;
    return consecutive;
}

int main() {
    cout << boolalpha << endl;

    vector<vector<int>> input {{2, 1, 6, 9, 5, 7, 8, 3}, {1,1,1,1}, {5,4,2,1}};

    // Display
    int answer {};
    for (auto &i : input) {
        answer = longestConsecutiveSequence(i);
        cout << "LongStreak : " << answer << endl;
    }

    cout << endl;
    return 0;
}