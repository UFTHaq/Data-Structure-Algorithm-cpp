#include <iostream>

int jumlah {};
void permutation(std::string &word, int left, int right) {
    if (left == right) {
        jumlah++;
        std::cout << jumlah << ": " << word << std::endl;
    } else {
        for (int i = left; i <= right; i++) {
            std::swap(word.at(left), word.at(i));
            permutation(word, left + 1, right);
            std::swap(word.at(left), word.at(i));
        }
    }
}

int main() {
    std::cout << std::endl;
    std::string word {"ABCDE"};

    int right = word.size() - 1;
    std::cout << "Permutation of " << word << ": " << std::endl;
    permutation(word, 0, right);

    std::cout << std::endl;
    return 0;
}