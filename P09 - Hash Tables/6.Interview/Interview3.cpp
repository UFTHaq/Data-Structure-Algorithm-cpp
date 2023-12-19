// FIRST NON REPEATING CHARACTER 

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

char firstNonRepeatingChar(const string &input_string) {
    unordered_map<char, int> MAP {};

    for (auto &i: input_string) {
        MAP[i]++;
    }

    for (auto &i: input_string) {
        if (MAP[i] == 1) {
            return i;
        }
    }
    return '\0';
}



int main() {
    cout << boolalpha << endl;

    string input_string {"programming"};

    cout << firstNonRepeatingChar(input_string);

    cout << "\n" << endl;
    return 0;
}