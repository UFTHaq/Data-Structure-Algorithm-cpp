#include <iostream>

int addItems(int n) {
    // O(1)         -> Karena hanya ada 1 proses
    return n + n;
}

int addItems2(int n) {
    // O(2)         -> Karena ada 2 proses, tetapi di Drop constant jadi O(1)
    return n + n + n;
}

int main() {
    std::cout << addItems(10) << std::endl;
    std::cout << addItems2(10) << std::endl;
    return 0;
}

// = O(1)