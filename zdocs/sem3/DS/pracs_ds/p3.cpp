#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& val) : data(val), next(nullptr) {}
};
template <typename T>
class CircularLinkedList {
private:
    Node<T>* cursor; // Points to the last node; cursor->next is the first node
public:
    CircularLinkedList() : cursor(nullptr) {}
    ~CircularLinkedList() {
        T temp;
        while (!isEmpty()) {
            removeFront(temp);
        }
    }
    bool isEmpty() const {
        return cursor == nullptr;
    }    
    void insert(const T& x) {   // i. Insert an element x in the list (at the end / after cursor)
        Node<T>* newNode = new Node<T>(x);
        if (isEmpty()) {
            newNode->next = newNode; // Points to itself
            cursor = newNode;
        } else {
            newNode->next = cursor->next; // Link new node to the front
            cursor->next = newNode;       // Link old last node to new node
            cursor = newNode;             // Advance cursor to new last node
        }
    }    
    bool removeFront(T& removedVal) {       // ii (a). Remove an element from the list (removes the front element: cursor->next)
        if (isEmpty()) {
            return false;
        }
        Node<T>* oldNode = cursor->next;
        removedVal = oldNode->data;
        if (oldNode == cursor) {            
            cursor = nullptr;   // Only one node in the list
        } else {
            cursor->next = oldNode->next;
        }
        delete oldNode;
        return true;
    }    
    bool removeElement(const T& x) {    // ii (b). Remove a specific element x from the list
        if (isEmpty()) {
            return false;
        }
        Node<T>* prev = cursor;
        Node<T>* curr = cursor->next;
        do {
            if (curr->data == x) {
                if (curr == cursor && curr->next == cursor) {                    
                    cursor = nullptr;       // Only one node in the list
                } else {
                    prev->next = curr->next;
                    if (curr == cursor) {                        
                        cursor = prev;      // Update cursor if the last node is being removed
                    }
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != cursor->next);
        return false;
    }    
    Node<T>* search(const T& x) const {     // iii. Search for an element x in the list and return its pointer
        if (isEmpty()) {
            return nullptr;
        }
        Node<T>* curr = cursor->next;
        do {
            if (curr->data == x) {
                return curr;
            }
            curr = curr->next;
        } while (curr != cursor->next);
        return nullptr;
    }    
    void display() const {      // Display all elements in the list
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* curr = cursor->next;
        cout << "Circular Linked List: ";
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != cursor->next);
        cout << "(back to " << cursor->next->data << ")\n";
    }
};
int main() {
    CircularLinkedList<int> cll;
    int choice, value, removedVal;
    do {
        cout << "\n--- Circular Linked List ADT Menu ---\n";
        cout << "1. Insert an element x\n";
        cout << "2. Remove front element\n";
        cout << "3. Remove a specific element x\n";
        cout << "4. Search for an element x\n";
        cout << "5. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> value;
                cll.insert(value);
                cout << value << " inserted.\n";
                break;
            case 2:
                if (cll.removeFront(removedVal)) {
                    cout << "Removed front element: " << removedVal << "\n";
                } else {
                    cout << "Underflow: List is empty.\n";
                }
                break;
            case 3:
                cout << "Enter element to remove: ";
                cin >> value;
                if (cll.removeElement(value)) {
                    cout << value << " removed from the list.\n";
                } else {
                    cout << "Element " << value << " not found.\n";
                }
                break;
            case 4: {
                cout << "Enter element to search: ";
                cin >> value;
                Node<int>* result = cll.search(value);
                if (result != nullptr) {
                    cout << "Element " << result->data
                         << " found at pointer address: " << result << "\n";
                } else {
                    cout << "Element " << value << " not found (returned nullptr).\n";
                }
                break;            }

            case 5:
                cll.display();
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