#include <iostream>

int main() {
    std::cout << std::endl;

    int num1 = 11;
    int num2 = num1;

    num1 = 22;

    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;

    std::cout << std::endl;
    return 0;
}