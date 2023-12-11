#include <iostream>

using namespace std;

class Node {
public:
    int node_value {};
    Node *node_next = nullptr;

    Node (int node_value) {
        this->node_value = node_value;
        this->node_next = nullptr;
    }
    ~Node() = default;
};


class LinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length {};

public:
    LinkedList(int node_value) {
        Node *newNode = new Node(node_value);
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
            cout << temp->node_value << endl;
            temp = temp->node_next;
        }
        std::cout << "---------------" << std::endl;
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        } else {
            cout << "Head: " << head->node_value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        } else { 
            cout << "Tail: " << tail->node_value << endl;
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

    void deleteFirst() {
        if (length == 0) return;

        Node *temp = head;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->node_next;
        }
        length--;

        delete temp;
    }

    Node *get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->node_next;
        }
        return temp;
    }

    bool setValue(int index, int value) {
        Node *temp = LinkedList::get(index);

        if (temp != nullptr) {
            temp->node_value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) {
            return false;
        } else if (index == 0) {
            LinkedList::prepend(value);
            return true;
        } else if (index == length) {
            LinkedList::append(value);
            return true;
        } else {
            Node *newNode = new Node(value);
            Node *temp = get(index - 1);
            newNode->node_next = temp->node_next;
            temp->node_next = newNode;
            length++;
            return true;
        }
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
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->deleteLast();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->prepend(10);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->deleteFirst();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    std::cout << myLinkedList->get(1)->node_value << std::endl;

    myLinkedList->setValue(1, 7);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->insert(1, 10);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    std::cout << std::endl;
    return 0;
}

