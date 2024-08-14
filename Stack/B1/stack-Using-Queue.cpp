#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    // Push operation 
    void push(int x) {
        q.push(x);
        // rotate the elements in the queue to make the last pushed element the front of the queue
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop operation
    void pop() {
        if (q.empty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        q.pop();
    }

    // Top operation 
    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;  
        }
        return q.front();
    }

    // Size operation 
    int size() {
        return q.size();
    }

    // Check if the stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // Should print 30
    cout << "Stack size: " << st.size() << endl; // Should print 3

    st.pop();

    cout << "Top element after pop: " << st.top() << endl; // Should print 20
    cout << "Stack size after pop: " << st.size() << endl; // Should print 2

    st.pop();
    st.pop();
    st.pop();  // stack underflow

    return 0;
}
