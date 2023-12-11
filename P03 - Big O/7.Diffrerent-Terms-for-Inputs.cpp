// Different terms for inputs 

#include <iostream>

void printItems(int a, int b) {
    // O(a)
    for (int i = 0; i < a; i++) {
        std::cout << i << std::endl;
    }

    // O(b)
    for (int j = 0; j < b; j++) {
        std::cout << j << std::endl;
    }
}
// O(a + b)

void printItems2(int a, int b) {
    // O(a*b)
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cout << i << j << std::endl;
        }
    }
}