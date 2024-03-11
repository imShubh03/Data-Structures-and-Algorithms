#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    cout<<myStack.top()<<endl;
    myStack.push(2);
    cout<<myStack.top()<<endl;
    myStack.push(3);
    cout<<myStack.top()<<endl;

    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
        cout << " successfullly popped ";
        if (!myStack.empty())
            cout << myStack.top() << endl;
    }
    cout << endl;

    return 0;
}
