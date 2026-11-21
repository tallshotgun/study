#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};
// AVL Tree ADT
class AVLTree {
private:
    Node* root;

    int height(Node* n) const {
        return n == nullptr ? 0 : n->height;
    }

    int getBalance(Node* n) const {
        return n == nullptr ? 0 : height(n->left) - height(n->right);
    }
    // Right rotation (LL Case)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }
    // Left rotation (RR Case)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }
    // Recursive insert with rebalancing
    Node* insertHelper(Node* node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }

        if (x < node->data) {
            node->left = insertHelper(node->left, x);
        } else if (x > node->data) {
            node->right = insertHelper(node->right, x);
        } else {
            cout << "Duplicate element ignored\n";
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int b = getBalance(node);
        // LL Case
        if (b > 1 && x < node->left->data) {
            return rightRotate(node);
        }
        // RR Case
        if (b < -1 && x > node->right->data) {
            return leftRotate(node);
        }
        // LR Case
        if (b > 1 && x > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL Case
        if (b < -1 && x < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    bool searchHelper(Node* node, int x) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == x) {
            return true;
        }
        if (x < node->data) {
            return searchHelper(node->left, x);
        }
        return searchHelper(node->right, x);
    }
    void inorderHelper(Node* node) const {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }
    void preorderHelper(Node* node) const {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        destroyTree(root);
    }
    void insert(int x) {
        root = insertHelper(root, x);
    }
    bool search(int x) const {
        return searchHelper(root, x);
    }
    void display() const {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return;
        }
        cout << "Inorder: ";
        inorderHelper(root);
        cout << "\nPreorder: ";
        preorderHelper(root);
        cout << "\n";
    }
};
int main() {
    AVLTree tree;
    int ch, x;
    do {
        cout << "\n1.Insert";
        cout << "\n2.Search";
        cout << "\n3.Display";
        cout << "\n4.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                tree.insert(x);
                break;
            case 2:
                cout << "Enter element: ";
                cin >> x;
                if (tree.search(x)) {
                    cout << "Element Found\n";
                } else {
                    cout << "Element Not Found\n";
                }
                break;
            case 3:
                tree.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 4);
    return 0;
}