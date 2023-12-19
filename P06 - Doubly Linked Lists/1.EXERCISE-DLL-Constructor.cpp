#include <iostream>

using namespace std;

class Node {
public:
    int value {};
    Node *next_node {nullptr};
    Node *prev_node {nullptr};

    Node (int value) {
        this->value = value;
        next_node = nullptr;
        prev_node = nullptr;
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
            head = head->next_node;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next_node;
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

};



int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "\nDoubly Linked List:\n";
    myDLL->printList();

    /*
        EXPECTED OUTPUT:
        ----------------
        Head: 7
        Tail: 7
        Length: 1

        Doubly Linked List:
        7

    */
        
}

