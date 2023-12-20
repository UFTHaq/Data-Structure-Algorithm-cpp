#include <iostream>

using namespace std;


void funcThree(int &stack) {
    stack++;
    cout << stack << ": Three" << endl;
}

void funcTwo(int &stack) {
    funcThree(stack);
    stack++;
    cout << stack << ": Two" << endl;
}

void funcOne(int &stack) {
    funcTwo(stack);
    stack++;
    cout << stack << ": One" << endl;
}

int stack {};

int main() {
    cout << endl;

    funcOne(stack);

    cout << endl;
    return 0;

}
