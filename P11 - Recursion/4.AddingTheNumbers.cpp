#include <iostream>
#include <vector>

int step {};
int addingTheNumber(std::vector<std::vector<int>> input) {
    if (step > input.at(1).at(0)) return 0;
    int number = input.at(0).at(0);
    input.at(0).erase(input.at(0).begin());
    step++;
    return number + addingTheNumber(input);
}

int main() {
    std::cout << std::endl;

    std::vector<std::vector<int>> input {{1,4,5,3,7,2},{4}};

    int answer = addingTheNumber(input);

    std::cout << "Sum: " << answer << std::endl;

    std::cout << std::endl;
    return 0;
}