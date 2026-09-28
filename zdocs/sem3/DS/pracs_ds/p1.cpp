#include <iostream>

using namespace std;

// Node structure for the Singly Linked List
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // i. Insert an element x at the beginning of the singly linked list
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        cout << x << " inserted at the beginning." << endl;
    }

    // ii. Insert an element x at the i-th position (0-indexed)
    void insertAtPosition(int x, int i) {
        if (i < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (i == 0) {
            insertAtBeginning(x);
            return;
        }

        Node* newNode = new Node(x);
        Node* current = head;
        
        for (int count = 0; count < i - 1 && current != nullptr; ++count) {
            current = current->next;
        }

        // If current is null, the position is greater than the list size
        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
        cout << x << " inserted at position " << i << "." << endl;
    }

    // iii. Remove an element from the beginning of the singly linked list
    void removeFromBeginning() {
        if (head == nullptr) {
            cout << "List is already empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " removed from the beginning." << endl;
        delete temp;
    }

    // iv. Remove an element from the i-th position (0-indexed)
    void removeFromPosition(int i) {
        if (i < 0 || head == nullptr) {
            cout << "Invalid position or list is empty!" << endl;
            return;
        }
        if (i == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        
        // Traverse to the (i-1)th node
        for (int count = 0; count < i - 1 && current->next != nullptr; ++count) {
            current = current->next;
        }

        // If the i-th node doesn't exist
        if (current->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        cout << nodeToDelete->data << " removed from position " << i << "." << endl;
        delete nodeToDelete;
    }

    // vi. Search for an element x and return its pointer
    Node* search(int x) {
        Node* current = head;
        int index = 0;
        
        while (current != nullptr) {
            if (current->data == x) {
                cout << "Element " << x << " found at position " << index << ". Pointer: " << current << endl;
                return current;
            }
            current = current->next;
            index++;
        }
        
        cout << "Element " << x << " not found in the list." << endl;
        return nullptr;
    }

    // Utility function to print the current state of the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free dynamically allocated memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SinglyLinkedList list;

    // i. Insert at beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.display();

    // ii. Insert at i-th position
    list.insertAtPosition(15, 2); 
    list.insertAtPosition(5, 0);  
    list.display();

    // vi. Search for an element
    list.search(15);
    list.search(100);

    // iv. Remove from i-th position
    list.removeFromPosition(3);
    list.display();

    // iii. Remove from beginning
    list.removeFromBeginning();
    list.display();

    return 0;
}