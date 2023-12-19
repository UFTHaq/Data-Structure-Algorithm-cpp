#include <iostream>

using namespace std;

class Node {
public:
    int value {};
    Node *next = nullptr;

    Node (int value) {
        this->value = value;
        this->next = next;
    }

    ~Node() = default;
};


class Queue {
private:
    Node *first = nullptr;
    Node *last = nullptr;
    int length {};

public:
    Queue(int value) {
        Node *newNode = new Node(value);
        first = newNode;
        last = newNode;
        length++;
    }

    ~Queue() {
        Node* temp = first;
        while (first) {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void printQueue() {
        Node* temp = first;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << "----------" << endl;
    }

    void getFirst() {
        if (first == nullptr) {
            cout << "First: nullptr" << endl;
        } else {
            cout << "First: " << first->value << endl;
        }
    }

    void getLast() {
        if (last == nullptr) {
            cout << "Last: nullptr" << endl;
        } else { 
            cout << "Last: " << last->value << endl;
        }  
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }
    
    bool isEmpty() {
        if (length == 0) return true;
        return false;
    }

    void enqueue(int value) {
        Node *newNode = new Node(value);

        if (first == nullptr) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

};



int main() {
        
    Queue* myQueue = new Queue(7);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();
    cout << "Queue:\n";
    myQueue->printQueue();

    myQueue->enqueue(10);
    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();
    cout << "Queue:\n";
    myQueue->printQueue();

    return 0;

}

