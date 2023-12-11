#include <iostream>

using namespace std;

class Node {
public:
    int value {};
    Node *node_next = nullptr;

    Node (int value) {
        this->value = value;
        node_next = nullptr;
    }
    ~Node() = default;
};


class LinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length {};

public:
    LinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length++;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->node_next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->node_next;
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

    void append(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->node_next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (head == nullptr) {
            return;
        }

        Node *temp = head;
        Node *pre = head;
        while (temp->node_next != tail->node_next) {
            pre = temp;
            temp = temp->node_next;
        }
        tail = pre;
        tail->node_next = nullptr;

        length--;

        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
    }

    void prepend(int val) {
        Node *newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }

        newNode->node_next = head;
        head = newNode;
        length++; 
    }
};




int main() {
    std::cout << std::endl;

    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->append(9);
    myLinkedList->append(2);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "\nLinked List:\n";
    myLinkedList->printList();

    myLinkedList->deleteLast();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "\nLinked List:\n";
    myLinkedList->printList();

    myLinkedList->prepend(10);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "\nLinked List:\n";
    myLinkedList->printList();

    std::cout << std::endl;
    return 0;
}

