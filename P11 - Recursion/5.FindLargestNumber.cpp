#include <iostream>
#include <vector>

int max {};
int findLargestNumber(std::vector<int> &vec) {
    if (vec.size() == 1) return vec.at(0);

    // remove from front is slower O(n) 
    // cause need to shifting
    // if (vec.at(0) > vec.at(1)) {
    //     vec.erase(vec.begin() + 1);
    // } else {
    //     vec.erase(vec.begin() + 0);
    // }
    // return findLargestNumber(vec);

    // remove from back is faster O(1)
    if (vec.at(vec.size() - 1) > vec.at(vec.size() - 2)) {
        vec.erase(vec.begin() + vec.size() - 2);
    } else {
        vec.pop_back();
    }
    return findLargestNumber(vec);
}

int main() {
    std::cout << std::endl;

    std::vector<int> vec {3,1,6,8,9,4,5};

    vec.clear();
    for (int i = 0; i < 20000; i++) {
        vec.push_back(i);
    }

    int answer = findLargestNumber(vec);
    std::cout << "Max: " << answer << std::endl;

    std::cout << std::endl;
    return 0;
}