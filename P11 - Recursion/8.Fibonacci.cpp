#include <iostream>
#include <vector>

int fibonacci(int num) {
    if (num < 2) return num;

    return fibonacci(num-1) + fibonacci(num-2);
}


int main() {
    std::cout << std::endl;

    int number {6};
    std::cout << fibonacci(number);

    std::cout << std::endl;
    return 0;
}