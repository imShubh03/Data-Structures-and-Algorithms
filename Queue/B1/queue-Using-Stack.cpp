#include <bits/stdc++.h>
using namespace std;

/*
class Queue {
    stack<int> s1, s2;
public:
    // Push operation (enqueue)
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element onto s1
        s1.push(x);

        // Move all elements back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Pop operation (dequeue)
    void pop() {
        if (s1.empty()) {
            cout << "Queue underflow" << endl;
            return;
        }
        s1.pop();
    }

    // Front operation (get the front element)
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }

    // Size operation (get the size of the queue)
    int size() {
        return s1.size();
    }

    // Check if the queue is empty
    bool empty() {
        return s1.empty();
    }
};
*/

class Queue {
private:
    stack<int> s1, s2;

public:
    // Enqueue operation (push to queue)
    void push(int x) {
        s1.push(x);
    }

    // Dequeue operation (remove from queue)
    void pop() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue underflow" << endl;
                return;
            }
            // Move all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get the front element (peek operation)
    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            // Move all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Get the size of the queue
    int size() {
        return s1.size() + s2.size();
    }

    // Check if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Should print 10
    cout << "Queue size: " << q.size() << endl;     // Should print 3

    q.pop();

    cout << "Front element after pop: " << q.front() << endl; // Should print 20
    cout << "Queue size after pop: " << q.size() << endl;     // Should print 2

    q.pop();
    q.pop();
    q.pop();  // Should indicate queue underflow

    return 0;
}
