#include <iostream>
#include <iomanip>

using namespace std;


class Node {
public:
    int value {};
    Node *right {nullptr};
    Node *left {nullptr};

    Node (int value) : value{value} {
    }

    ~Node() = default;
};


class BinarySearchTree {
public:
    Node *root {nullptr};


public:
    BinarySearchTree() = default;
    
    // ---------------------------------------------------
    //  Below is a helper function used by the destructor
    //  Deletes all nodes in BST
    //  Similar to DFS PostOrder in Tree Traversal section
    // ---------------------------------------------------
    void destroy(Node* currentNode) {
        if (currentNode->left) destroy(currentNode->left);
        if (currentNode->right) destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { 
        destroy(root); 
    }

    bool insert(int value) {
        Node *newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        
        Node *temp = root;

        while (true) {
            if (newNode->value == temp->value) {
                return false;
            }

            if (newNode->value < temp->value) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return true;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                } else {
                    temp = temp->right;
                }
            }
        }
         
    }

    bool contains(int value) {
        Node *temp = root;
        while (temp != nullptr) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }

};



int main() {
    cout << boolalpha << endl;
        
    BinarySearchTree* myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root << endl;

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);


    myBST->insert(27);

    cout << "Loc of 27: " << myBST->root->left->right << endl;
    cout << "Loc of 27: " << myBST->root->left->right->value << endl;

    cout << "Contains 27: " << myBST->contains(27) << endl;
    cout << "Contains 17: " << myBST->contains(17) << endl;

    cout << endl;
    return 0;
}

