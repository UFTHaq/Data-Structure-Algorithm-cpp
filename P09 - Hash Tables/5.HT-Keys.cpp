#include <iostream>
#include <vector>

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

    void set(string key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node* temp = dataMap[index];
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // int get(string key) {
    //     int index = hash(key);
    //     if (dataMap[index] == nullptr) return INT_MIN;
    //     else {
    //         Node* temp = dataMap[index];
    //         while (temp->key != key) {
    //             temp = temp->next;
    //         }
    //         return temp->value;
    //     }
    // }
        
    int get(string key) {
        int index = hash(key);
        Node *temp = dataMap[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return INT_MIN;
    }

    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node *temp = dataMap[i];
            while (temp != nullptr) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        cout << "[ ";
        for (auto &i : allKeys) {
            cout << i << " ";
        }
        cout << "]" << endl;
        return allKeys;
    }
};


int main() {
    cout << endl;

    HashTable* myHashTable = new HashTable();

    myHashTable->set("paint", 20);
    myHashTable->set("bolts", 40);
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);
    myHashTable->printTable();

    std::cout << "Tile: " << myHashTable->get("tile") << endl;
    std::cout << "Lumber: " << myHashTable->get("lumber") << endl;
    std::cout << "Books: " << myHashTable->get("books") << endl;

    vector<string> myKeys = myHashTable->keys();
    

    cout << endl;
    return 0;
}

