#include <iostream>

using namespace std;

class Node {
public:
    int value_node {};
    Node *next_node = nullptr;

    Node (int value_node) {
        this->value_node = value_node;
        this->next_node = nullptr;
    }
    ~Node() = default;
};


class LinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length {};

public:
    LinkedList(int value_node) {
        Node *newNode = new Node(value_node);
        head = newNode;
        tail = newNode;
        length++;
    }

    ~LinkedList() {
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
            cout << temp->value_node << endl;
            temp = temp->next_node;
        }
        std::cout << "---------------" << std::endl;
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        } else {
            cout << "Head: " << head->value_node << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        } else { 
            cout << "Tail: " << tail->value_node << endl;
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
            tail->next_node = newNode;
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
        while (temp->next_node != tail->next_node) {
            pre = temp;
            temp = temp->next_node;
        }
        tail = pre;
        tail->next_node = nullptr;

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

        newNode->next_node = head;
        head = newNode;
        length++; 
    }

    void deleteFirst() {
        if (length == 0) return;

        Node *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next_node;
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
            temp = temp->next_node;
        }
        return temp;
    }

    bool setValue(int index, int value) {
        Node *temp = LinkedList::get(index);

        if (temp != nullptr) {
            temp->value_node = value;
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
            newNode->next_node = temp->next_node;
            temp->next_node = newNode;
            length++;
            return true;
        }
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            return;
        } else if (index == 0) {
            LinkedList::deleteFirst();
        } else if (index == length - 1) {
            LinkedList::deleteLast();
        } else {
            Node *prev = get(index - 1);
            Node *temp = prev->next_node;
            prev->next_node = temp->next_node;
            temp->next_node = nullptr;

            length--;
            delete temp;
        }
    }

    void reverse() {
        Node *temp = head;
        head = tail;
        tail = temp;

        Node* before = nullptr;
        Node* after = temp->next_node;

        for (int i = 0; i < length; i++) {
            after = temp->next_node;
            temp->next_node = before;
            before = temp;
            temp = after;
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

    std::cout << myLinkedList->get(1)->value_node << std::endl;

    myLinkedList->setValue(1, 7);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->insert(1, 2);
    myLinkedList->insert(1, 10);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->deleteNode(1);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    myLinkedList->reverse();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    cout << "Linked List:\n";
    myLinkedList->printList();

    std::cout << std::endl;
    return 0;
}

