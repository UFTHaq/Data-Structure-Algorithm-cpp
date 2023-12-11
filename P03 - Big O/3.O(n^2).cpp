#include <iostream>

using namespace std;


void printItems(int n) {
    // O(n^2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }
}


int main() { 

    printItems(10);

}

// = O(n^2)