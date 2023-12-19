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
        cout << "Hash Table: \n";
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
        cout << "================\n" << endl;
    }

    int hash(string key) {
        int hash {};
        for (auto &i : key) {
            int asciiValue = int(i);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }


};


int main() {
    cout << endl;

    HashTable* myHashTable = new HashTable();

    myHashTable->printTable();

    cout << endl;
    return 0;
}

