#include <iostream>

using namespace std;

class Node {
public:
    string key {};
    int value {};
    Node* next {nullptr};

    Node(string key, int value) : key{key}, value{value} {}
};

class HashTable {
private:
    static const int SIZE {7};
    Node* dataMap[SIZE];

public:
    // ---------------------------------------------------
    //  Destructor code is similar to keys() function
    //  Watch that video to help understand how this works
    // ---------------------------------------------------
    ~HashTable() {
        for(int i = 0; i < SIZE; i++) {
            Node* head = dataMap[i];
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }
    
    void printTable() {
        for(int i = 0; i < SIZE; i++) {
            cout << i << ":" << endl;
            if(dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }
        
};


int main() {
    cout << endl;

    HashTable* myHashTable = new HashTable();

    cout << "Hash Table: \n";
    myHashTable->printTable();

    /*
        EXPECTED OUTPUT:
        ----------------
        Hash Table: 
        0:
        1:
        2:
        3:
        4:
        5:
        6:

    */  

    cout << endl;
    return 0;
}

