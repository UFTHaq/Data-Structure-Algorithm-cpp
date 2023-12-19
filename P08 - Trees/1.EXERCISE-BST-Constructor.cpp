#include <iostream>

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

};



int main() {
    cout << endl;
        
    BinarySearchTree* myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 0x0

    */
    cout << endl;
    return 0;
}

