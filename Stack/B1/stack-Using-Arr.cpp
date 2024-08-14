#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int size;
    int top;
    int *arr;

    // constructor to initialize with size
    Stack(int n) {
        size = n;
        top = -1;
        arr = new int[size];
    }

    void push(int x) {
        // if top exceeds size
        if (top >= size - 1) {
            cout << "can't push further... stack overflow" << endl;
            return; 
        }

        top = top + 1;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "can't pop further... stack underflow" << endl;
            return -1; 
        }

        int ele = arr[top];
        top--;
        return ele;
    }

    int peek() { // renamed from top() to peek()
        if (top == -1) {
            cout << "stack is empty" << endl;
            return -1; 
        }
        return arr[top];
    }

    int currentSize() { // renamed from size() to currentSize()
        return top + 1;
    }
};

int main() {
    
    Stack st(4);

    st.push(4);
    st.push(2);
    st.push(6);

    cout << "Top element: " << st.peek() << endl; 
    cout << "Current size: " << st.currentSize() << endl; 

    st.pop();
    cout << "Top element after 1st pop: " << st.peek() << endl;

    st.push(8);
    cout << "Top element: " << st.peek() << endl; 



    return 0;
}
