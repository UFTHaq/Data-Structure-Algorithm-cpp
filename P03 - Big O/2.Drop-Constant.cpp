#include <iostream>

using namespace std;


void printItems(int n) {
    // O(n)
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
    
    // O(n)
    for (int j = 0; j < n; j++) {
        cout << j << endl;
    }

}


int main() { 

    printItems(10);

}

// = O(n) + O(n)
// = O(2n)
// Drop the Constant
// = O(n)