#include <iostream>

using namespace std;

class Node {
public:
    int value {};
    Node *next {nullptr};

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }

    ~Node() = default;
};

class Stack {
private:
    Node *top = nullptr;
    int height {};

public:
    Stack(int value) {
        Node *newNode = new Node(value);
        top = newNode;
        height++;
    }
    
    ~Stack() {
        Node* temp = top;
        while (top) {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack() {
        cout << "Stack:\n";
        Node* temp = top;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << "----------" << endl;
    }

    void getTop() {
        if (top == nullptr) {
            cout << "Top: nullptr" << endl;
        } else {
            cout << "Top: " << top->value << endl;
        }
    }

    void getHeight() {
        cout << "Height: " << height << endl;
    }

    void push(int value) {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

};



int main() {
    cout << endl;
        
    Stack* myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();

    myStack->push(5);
    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();

    cout << endl;
    return 0;
}

