#include <iostream>

std::string reverseString(std::string word) {
    if (word == "") return "";
    char last = word[0];
    word.erase(word.begin());
    return reverseString(word) + last;
}


int main() {
    std::cout << std::endl;

    std::string word {"Covid 19"};

    // delete first element of string
    // word.erase(word.begin());

    std::string test = reverseString(word);

    std::cout << test << std::endl;

    std::cout << std::endl;
    return 0;
}

// fast code
// include <algorithm>
// std::reverse(word.begin(), word.end());