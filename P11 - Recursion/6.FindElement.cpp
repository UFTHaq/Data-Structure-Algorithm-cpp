#include <iostream>
#include <vector>

bool findElement(std::vector<std::vector<int>> &vec) {
    if (vec.at(0).size() == 0) return false;
    if (vec.at(0).at(vec.at(0).size() - 1) == vec.at(1).at(0)) return true;
    vec.at(0).pop_back();
    return findElement(vec);
}

int main() {
    std::cout << std::boolalpha << std::endl;

    std::vector<std::vector<int>> vec {{3,1,6,8,2,4,5}, {8}};

    bool answer = findElement(vec);

    std::cout << "Find: " << answer << std::endl;

    std::cout << std::endl;
    return 0;
}