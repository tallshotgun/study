#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>   // Doubly Linked List ADT
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}    
    ~DoublyLinkedList() {
        T temp;
        while (!isEmpty()) {
            removeFromBeginning(temp);
        }
    }
    bool isEmpty() const {
        return head == nullptr;
    }    
    void insertAtBeginning(const T& x) {    // i. Insert an element x at the beginning of the doubly linked list
        Node<T>* newNode = new Node<T>(x);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }    
    void insertAtEnd(const T& x) {  // ii. Insert an element x at the end of the doubly linked list
        Node<T>* newNode = new Node<T>(x);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }    
    bool removeFromBeginning(T& removedVal) {   // iii. Remove an element from the beginning of the doubly linked list
        if (isEmpty()) {
            return false;
        }
        Node<T>* oldHead = head;
        removedVal = oldHead->data;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete oldHead;
        return true;
    }    
    bool removeFromEnd(T& removedVal) {     // iv. Remove an element from the end of the doubly linked list
        if (isEmpty()) {
            return false;
        }
        Node<T>* oldTail = tail;
        removedVal = oldTail->data;
        if (head == tail) {            
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete oldTail;
        return true;
    }
    void displayForward() const {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* curr = head;
        cout << "Forward:  NULL <-> ";
        while (curr != nullptr) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }  
    void displayBackward() const {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* curr = tail;
        cout << "Backward: NULL <-> ";
        while (curr != nullptr) {
            cout << curr->data << " <-> ";
            curr = curr->prev;
        }
        cout << "NULL\n";
    }
};
int main() {
    DoublyLinkedList<int> dll;
    int choice, value, removedVal;
    do {
        cout << "\n--- Doubly Linked List ADT Menu ---\n";
        cout << "1. Insert an element x at the beginning\n";
        cout << "2. Insert an element x at the end\n";
        cout << "3. Remove an element from the beginning\n";
        cout << "4. Remove an element from the end\n";
        cout << "5. Display list (forward & backward)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> value;
                dll.insertAtBeginning(value);
                cout << value << " inserted at the beginning.\n";
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> value;
                dll.insertAtEnd(value);
                cout << value << " inserted at the end.\n";
                break;
            case 3:
                if (dll.removeFromBeginning(removedVal)) {
                    cout << "Removed element from beginning: " << removedVal << "\n";
                } else {
                    cout << "Underflow: List is empty.\n";
                }
                break;
            case 4:
                if (dll.removeFromEnd(removedVal)) {
                    cout << "Removed element from end: " << removedVal << "\n";
                } else {
                    cout << "Underflow: List is empty.\n";
                }
                break;
            case 5:
                dll.displayForward();
                dll.displayBackward();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}