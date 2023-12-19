#include <iostream>

using namespace std;

class Node {
public:
    int value {};
    Node *next {nullptr};
    Node *prev {nullptr};

    Node (int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

    ~Node() = default;
};


class DoublyLinkedList {
private:
    Node *head {nullptr};
    Node *tail {nullptr};
    int length {};

public:
    DoublyLinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length++;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        std::cout << "---------------" << std::endl;
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        } else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        } else { 
            cout << "Tail: " << tail->value << endl;
        }  
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(int value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (head == nullptr) {
            return;
        }

        if (tail->prev == nullptr) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }

        length--;
    }

};



int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "Doubly Linked List:\n";
    myDLL->printList();

    myDLL->append(3);
    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "Doubly Linked List:\n";
    myDLL->printList();

    myDLL->deleteLast();
    myDLL->deleteLast();
    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "Doubly Linked List:\n";
    myDLL->printList();
}

