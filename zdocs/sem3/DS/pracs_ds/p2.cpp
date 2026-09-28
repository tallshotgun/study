#include <iostream>

using namespace std;

// Node structure for the Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail; // Maintaining a tail pointer makes end operations O(1)

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // i. Insert an element x at the beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        
        if (head == nullptr) {
            // If the list is empty, the new node is both head and tail
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << x << " inserted at the beginning." << endl;
    }

    // ii. Insert an element x at the end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        
        if (tail == nullptr) {
            // If the list is empty, the new node is both head and tail
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << x << " inserted at the end." << endl;
    }

    // iii. Remove an element from the beginning
    void removeFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Cannot remove from the beginning." << endl;
            return;
        }
        
        Node* temp = head;
        if (head == tail) {
            // Only one node in the list
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        cout << temp->data << " removed from the beginning." << endl;
        delete temp;
    }

    // iv. Remove an element from the end
    void removeFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty! Cannot remove from the end." << endl;
            return;
        }
        
        Node* temp = tail;
        if (head == tail) {
            // Only one node in the list
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        cout << temp->data << " removed from the end." << endl;
        delete temp;
    }

    // Utility function to print the list forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* current = head;
        cout << "Forward: NULL <- ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " <-> ";
            current = current->next;
        }
        cout << " -> NULL" << endl;
    }

    // Destructor to free dynamically allocated memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // i. Insert at the beginning
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(10);
    dll.displayForward();

    // ii. Insert at the end
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.displayForward();

    // iii. Remove from the beginning
    dll.removeFromBeginning();
    dll.displayForward();

    // iv. Remove from the end
    dll.removeFromEnd();
    dll.displayForward();

    return 0;
}