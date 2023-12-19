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
        } else if (tail->prev == nullptr) {
            // Only one node in the list
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            // More than one node in the list
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        length--;
    }

    void prepend(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (head == nullptr) {
            return;
        } else if (head->next == nullptr) {
            // Only one node in the list
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            // More than one node in the list
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        length--;
    }

    Node *get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        Node *temp = head;
        if (index < (length/2)) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = (length-1); i > index; i--) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value) {
        Node *temp = DoublyLinkedList::get(index);

        if (temp != nullptr) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) {
            return false;
        } else if (index == 0) {
            DoublyLinkedList::prepend(value);
            return true;
        } else if (index == length) {
            DoublyLinkedList::append(value);
            return true;
        } else {
            Node *newNode = new Node(value);
            Node *temp = get(index - 1);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;

            temp = nullptr;
            length++;
            return true;
        }
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            return;
        } else if (index == 0) {
            DoublyLinkedList::deleteFirst();
        } else if (index == length - 1) {
            DoublyLinkedList::deleteLast();
        } else {
            Node *temp = get(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
            temp = nullptr;
            length--;
        }
    }

};



int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(0);
    myDLL->append(1);
    myDLL->append(2);
    myDLL->append(3);

    myDLL->set(3, 7);
    myDLL->printList();

    myDLL->insert(2, 10);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();
    cout << "Doubly Linked List:\n";
    myDLL->printList();

    myDLL->deleteNode(3);
    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();
    cout << "Doubly Linked List:\n";
    myDLL->printList();

    return 0;
}

