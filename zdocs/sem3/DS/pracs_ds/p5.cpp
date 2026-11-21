#include <iostream>
using namespace std;
#define SIZE 5
// Queue ADT
class Queue {
private:
    int q[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    // Insert element
    void enqueue(int x) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        q[rear] = x;
    }
    // Delete element
    void dequeue() {
        if (front == -1) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Deleted: " << q[front] << "\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    // Display
    void display() {
        if (front == -1) {
            cout << "Queue Empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};
int main() {
    Queue obj;
    int ch, x;
    do {
        cout << "\n1.Enqueue  2.Dequeue";
        cout << "\n3.Display  4.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                obj.enqueue(x);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(ch != 4);
    return 0;
}