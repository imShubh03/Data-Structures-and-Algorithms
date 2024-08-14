#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int *arr;
    int maxSize;
    int currSize;
    int start;
    int end;

    Queue(int n) {
        maxSize = n;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int ele) {
        if (currSize == maxSize) {
            cout << "can't push further... queue overflow" << endl;
            return;
        }

        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = ele;
        currSize++;
    }

    int pop() {
        if (start == -1) {
            cout << "queue is empty" << endl;
            return -1;
        }
        int topop = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return topop;
    }

    int top() {
        if (start == -1) {
            cout << "queue underflow..." << endl;
            return -1; // return an invalid value indicating an error
        }
        return arr[start];
    }

    int size() {
        return currSize; // return current size of the queue
    }
};

int main() {

    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.size() << endl;
    cout << "The first element to be deleted: " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.size() << endl;

    return 0;
}
