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

class Stack {
public:
    Node* top;
    int size;

    // Initialize top to nullptr and size to 0
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Push operation
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop operation
    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return -1;
        }

        int popVal = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return popVal;
    }

    // Peek operation
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Get total size of the stack
    int totalSize() {
        return size;
    }

    // Print the stack elements
    void print() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();

    cout << "Top element: " << st.peek() << endl;
    cout << "Popped element: " << st.pop() << endl;
    st.print();

    return 0;
}
