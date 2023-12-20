#include <iostream>
#include <vector>

int fibonacci(int num, std::vector<int>& fibVec) {
    if (num <= 1) {
        fibVec[num] = num;
        return num;
    }

    if (fibVec[num] != -1) {
        return fibVec[num];
    }

    fibVec[num] = fibonacci(num - 1, fibVec) + fibonacci(num - 2, fibVec);
    return fibVec[num];
}

int main() {
    std::cout << std::endl;

    int number {10};
    std::vector<int> fibVec(number + 1, -1);  // Initialize vector with -1

    int result = fibonacci(number, fibVec);

    std::cout << "Fibonacci(" << number << ") = " << result << std::endl;

    // Display the Fibonacci sequence stored in the vector
    std::cout << "Fibonacci sequence up to " << number << ": ";
    for (int i = 1; i <= number; ++i) {
        std::cout << fibVec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}
