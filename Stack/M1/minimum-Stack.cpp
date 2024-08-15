#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
        // Constructor does not need to do anything
    }
    
    void push(int val) {
        if (st.empty()) {
            // If stack is empty, push value as both element and minimum
            st.push({val, val}); 
        } else {
             // Push the value and the current minimum
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop(); 
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second; 
    }
};

int main() {
    MinStack minStack;

    // Example operations
    minStack.push(5);
    cout << "Top: " << minStack.top() << endl;    // Should print 5
    cout << "Min: " << minStack.getMin() << endl;  // Should print 5
    
    minStack.push(3);
    cout << "Top: " << minStack.top() << endl;    // Should print 3
    cout << "Min: " << minStack.getMin() << endl;  // Should print 3
    
    minStack.push(7);
    cout << "Top: " << minStack.top() << endl;    // Should print 7
    cout << "Min: " << minStack.getMin() << endl;  // Should print 3

    return 0;
}
