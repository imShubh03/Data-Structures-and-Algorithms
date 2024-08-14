#include <bits/stdc++.h>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
public:
    Node* start;  // Pointer to the front of the queue
    Node* end;    // Pointer to the rear of the queue
    int size;

    // Constructor to initialize the queue
    Queue() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    // Enqueue operation (push)
    void push(int val) {
        Node* newNode = new Node(val);
        if (end == nullptr) {
            // If the queue is empty, both start and end point to the new node
            start = end = newNode;
        } else {
            // Add the new node at the end of the queue and update the end pointer
            end->next = newNode;
            end = newNode;
        }
        size++;
        cout << "Pushed " << val << " into the queue" << endl;
    }

    // Dequeue operation (pop)
    int pop() {
        if (start == nullptr) {
            cout << "Queue underflow" << endl;
            return -1;
        }

        int deqVal = start->data;
        Node* temp = start;
        start = start->next;

        // If the queue becomes empty after popping, set end to nullptr
        if (start == nullptr) {
            end = nullptr;
        }

        delete temp;
        size--;
        return deqVal;
    }

    // Peek operation
    int peek() {
        if (start == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return start->data;
    }

    // Get total size of the queue
    int totalSize() {
        return size;
    }

    // Print the queue elements
    void print() {
        if (start == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = start;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.print();

    cout << "Front element: " << q.peek() << endl;
    cout << "Popped element: " << q.pop() << endl;
    q.print();

    return 0;
}
