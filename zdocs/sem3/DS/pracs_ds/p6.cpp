#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Binary Search Tree ADT
class BST {
private:
    Node* root;
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
    Node* findMin(Node* node) const {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node* deleteHelper(Node* node, int x, bool& deleted) {
        if (node == nullptr) {
            return nullptr;
        }

        if (x < node->data) {
            node->left = deleteHelper(node->left, x, deleted);
        } else if (x > node->data) {
            node->right = deleteHelper(node->right, x, deleted);
        } else {
            deleted = true;
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data, deleted);
        }
        return node;
    }
    void preorderHelper(Node* node) const {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }
    void inorderHelper(Node* node) const {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }
    void postorderHelper(Node* node) const {
        if (node != nullptr) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
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
    BST() : root(nullptr) {}
    ~BST() {
        destroyTree(root);
    }
    // i. Insert an element x
    void insert(int x) {
        root = insertHelper(root, x);
    }
    // ii. Delete an element x
    void deleteNode(int x) {
        bool deleted = false;
        root = deleteHelper(root, x, deleted);
        if (deleted) {
            cout << "Deleted: " << x << "\n";
        } else {
            cout << "Element not found\n";
        }
    }
    // iii. Search for an element x
    bool search(int x) const {
        return searchHelper(root, x);
    }
    // iv. Traversals
    void preorder() const {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return;
        }
        cout << "Preorder: ";
        preorderHelper(root);
        cout << "\n";
    }
    void inorder() const {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return;
        }
        cout << "Inorder: ";
        inorderHelper(root);
        cout << "\n";
    }
    void postorder() const {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return;
        }
        cout << "Postorder: ";
        postorderHelper(root);
        cout << "\n";
    }
};
int main() {
    BST tree;
    int ch, x;
    do {
        cout << "\n1.Insert  2.Delete  3.Search";
        cout << "\n4.Preorder  5.Inorder  6.Postorder";
        cout << "\n7.Exit";
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
                tree.deleteNode(x);
                break;
            case 3:
                cout << "Enter element: ";
                cin >> x;
                if (tree.search(x)) {
                    cout << "Element found\n";
                } else {
                    cout << "Element not found\n";
                }
                break;
            case 4:
                tree.preorder();
                break;
            case 5:
                tree.inorder();
                break;
            case 6:
                tree.postorder();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 7);
    return 0;
}