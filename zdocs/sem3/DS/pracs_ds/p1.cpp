#include <iostream>
using namespace std;

template <typename T>   // Node structure for the Singly Linked List
struct Node {
    T data;
    Node<T>* next;
    Node(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    int size;
public:
    SinglyLinkedList() : head(nullptr), size(0) {}    
    ~SinglyLinkedList() {   // Destructor to free dynamically allocated memory
        T temp;
        while (!isEmpty()) {
            removeFromBeginning(temp);
        }
    }
    bool isEmpty() const {
        return head == nullptr;
    }
    int getSize() const {
        return size;
    }    
    void insertAtBeginning(const T& x) {    // i. Insert an element x at the beginning of the singly linked list
        Node<T>* newNode = new Node<T>(x);
        newNode->next = head;
        head = newNode;
        size++;
    }    
    bool insertAtPosition(const T& x, int pos) {    // ii. Insert an element x at the i-th position (1-based indexing)
        if (pos < 1 || pos > size + 1) {
            return false; // Invalid position
        }
        if (pos == 1) {
            insertAtBeginning(x);
            return true;
        }
        Node<T>* curr = head;
        for (int i = 1; i < pos - 1; ++i) {
            curr = curr->next;
        }
        Node<T>* newNode = new Node<T>(x);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
        return true;
    }    
    bool removeFromBeginning(T& removedVal) {   // iii. Remove an element from the beginning of the singly linked list
        if (isEmpty()) {
            return false;
        }
        Node<T>* oldHead = head;
        removedVal = oldHead->data;
        head = head->next;
        delete oldHead;
        size--;
        return true;
    }    
    bool removeFromPosition(int pos, T& removedVal) {   // iv. Remove an element from the i-th position (1-based indexing)
        if (isEmpty() || pos < 1 || pos > size) {
            return false; // Empty list or invalid position
        }
        if (pos == 1) {
            return removeFromBeginning(removedVal);
        }
        Node<T>* curr = head;
        for (int i = 1; i < pos - 1; ++i) {
            curr = curr->next;
        }
        Node<T>* target = curr->next;
        removedVal = target->data;
        curr->next = target->next;
        delete target;
        size--;
        return true;
    }    
    Node<T>* search(const T& x) const {     // v. Search for an element x in the singly linked list and return its pointer
        Node<T>* curr = head;
        while (curr != nullptr) {
            if (curr->data == x) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }    
    void display() const {      // Display all elements in the list
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* curr = head;
        cout << "Singly Linked List: ";
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    SinglyLinkedList<int> sll;
    int choice, value, pos, removedVal;
    do {
        cout << "\n--- Singly Linked List ADT Menu ---\n";
        cout << "1. Insert an element x at the beginning\n";
        cout << "2. Insert an element x at i-th position\n";
        cout << "3. Remove an element from the beginning\n";
        cout << "4. Remove an element from i-th position\n";
        cout << "5. Search for an element x\n";
        cout << "6. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> value;
                sll.insertAtBeginning(value);
                cout << value << " inserted at the beginning.\n";
                break;
            case 2:
                cout << "Enter element to insert: ";
                cin >> value;
                cout << "Enter position (1 to " << sll.getSize() + 1 << "): ";
                cin >> pos;
                if (sll.insertAtPosition(value, pos)) {
                    cout << value << " inserted at position " << pos << ".\n";
                } else {
                    cout << "Invalid position.\n";
                }
                break;
            case 3:
                if (sll.removeFromBeginning(removedVal)) {
                    cout << "Removed element from beginning: " << removedVal << "\n";
                } else {
                    cout << "Underflow: List is empty.\n";
                }
                break;
            case 4:
                if (sll.isEmpty()) {
                    cout << "Underflow: List is empty.\n";
                    break;
                }
                cout << "Enter position to remove (1 to " << sll.getSize() << "): ";
                cin >> pos;
                if (sll.removeFromPosition(pos, removedVal)) {
                    cout << "Removed element " << removedVal << " from position " << pos << ".\n";
                } else {
                    cout << "Invalid position.\n";
                }
                break;
            case 5: {
                cout << "Enter element to search: ";
                cin >> value;
                Node<int>* result = sll.search(value);
                if (result != nullptr) {
                    cout << "Element " << result->data
                         << " found at pointer address: " << result << "\n";
                } else {
                    cout << "Element " << value << " not found (returned nullptr).\n";
                }
                break;
            }
            case 6:
                sll.display();
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