#include <iostream>
#include <vector>

bool isPalidrome(std::string input) {
    if (input.size() <= 1) return true;
    if (input.at(0) != input.at(input.size() - 1)) return false;
    input.erase(input.begin());
    input.pop_back();
    return isPalidrome(input);
}

int main() {
    std::cout << std::boolalpha << std::endl;

    std::vector<std::string> input {"madam", "covid", "ukhem", "a"};
    // std::string input {"madam"};

    for (auto &i : input) {
        bool answer = isPalidrome(i);
        std::cout << i << " is Palindrome: " << answer << std::endl;
    }

    std::cout << std::endl;
    return 0;
}