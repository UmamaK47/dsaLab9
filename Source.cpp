#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root=nullptr;

public:
    bool isEmpty();
    void makeTree(int value);
    void leftChild(int value);
    void rightChild(int value);
    void siblings(int value);
    Node* findNode(int value);
};

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

void BinaryTree::makeTree(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (isEmpty()) {
        root = newNode;
        cout << "Root node created with value " << value << ".\n";
    }
    else {
        Node* current = root;
        Node* parent = nullptr;

        while (current) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            }
            else if (value > current->data) {
                current = current->right;
            }
            else {
                cout << "Value " << value << " already exists in the tree.\n";
                return;
            }
        }
        if (value < parent->data) {
            parent->left = newNode;
            cout << "Node with value " << value << " added to the left of " << parent->data << ".\n";
        }
        else {
            parent->right = newNode;
            cout << "Node with value " << value << " added to the right of " << parent->data << ".\n";
        }
    }
}


void BinaryTree::leftChild(int value) {
    if (isEmpty()) {
        cout << "The tree is empty. Add nodes first.\n";
        return;
    }

    Node* current = findNode(value);
    if (current) {
        if (current->left) {
            cout << "Left child of " << value << " is " << current->left->data << ".\n";
        }
        else {
            cout << value << " does not have a left child.\n";
        }
    }
    else {
        cout << value << " is not found in the tree.\n";
    }
}


void BinaryTree::rightChild(int value) {
    if (isEmpty()) {
        cout << "The tree is empty. Add nodes first.\n";
        return;
    }

    Node* current = findNode(value);
    if (current) {
        if (current->right) {
            cout << "Right child of " << value << " is " << current->right->data << ".\n";
        }
        else {
            cout << value << " does not have a right child.\n";
        }
    }
    else {
        cout << value << " is not found in the tree.\n";
    }
}

void BinaryTree::siblings(int value) {
    if (isEmpty()) {
        cout << "The tree is empty. Add nodes first.\n";
        return;
    }

    Node* parent = nullptr;
    Node* current = findNode(value);
    if (!current) {
        cout << value << " is not found in the tree.\n";
        return;
    }

    while (current && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (!parent) {
        cout << value << " has no siblings.\n";
        return;
    }

    if (parent->left && parent->left->data == value && parent->right) {
        cout << "Sibling of " << value << " is " << parent->right->data << ".\n";
    }
    else if (parent->right && parent->right->data == value && parent->left) {
        cout << "Sibling of " << value << " is " << parent->left->data << ".\n";
    }
    else {
        cout << value << " has no siblings.\n";
    }
}

Node* BinaryTree::findNode(int value) {
    Node* current = root;
    while (current) {
        if (value == current->data) {
            return current;
        }
        else if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr;
}


int getValidInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }
    return value;
}

int main() {
    BinaryTree bst;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Node to Tree\n";
        cout << "2. Find Left Child\n";
        cout << "3. Find Right Child\n";
        cout << "4. Find Sibling\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        choice = getValidInt();

        switch (choice) {
        case 1:
            cout << "Enter value to add: \n";
            value = getValidInt();
            bst.makeTree(value);
            break;
        case 2:
            cout << "Enter node value to find left child: \n";
            value = getValidInt();
            bst.leftChild(value);
            break;
        case 3:
            cout<<"Enter node value to find right child : \n";
            value = getValidInt();
            bst.rightChild(value);
            break;
        case 4:
            cout << "Enter node value to find sibling: \n";
            value = getValidInt();
            bst.siblings(value);
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}