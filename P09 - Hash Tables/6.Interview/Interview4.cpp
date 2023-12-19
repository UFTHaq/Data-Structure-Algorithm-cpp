// GROUP ANAGRAMS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &strings) {
    unordered_map <string, vector<string>> MAP {};

    for (const string &str: strings) {
        string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());

        MAP[sortedStr].push_back(str);
    }

    vector<vector<string>> result {};
    for (const auto &entry: MAP) {
        result.push_back(entry.second);
    }

    return result;
}

void printGroups(const vector<vector<string>>& groups) {
    cout << "{ ";
    for (const auto& group : groups) {
        cout << "( ";
        for (const string& str : group) {
            cout << "'" << str << "'" << " ";
        }
        cout << ") ";
    }
    cout << "}\n";
}

int main() {
    cout << boolalpha << endl;

    vector<string> strings {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> test = groupAnagrams(strings);
    printGroups(test);

    cout << "\n" << endl;
    return 0;
}