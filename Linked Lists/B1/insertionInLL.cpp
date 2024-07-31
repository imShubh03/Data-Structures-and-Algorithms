#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node with given data
    Node(int d) {
        data = d;
        next = nullptr;
    }

    // Constructor to initialize node with given data and next pointer
    Node(int d, Node* nextNode) {
        data = d;
        next = nextNode;
    }
};

class Solution {
public:
    Node* convertArr2LL(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return nullptr;

        Node* head = new Node(arr[0]);
        Node* mover = head;

        for (int i = 1; i < n; i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            // Update mover
            mover = mover->next;
        }
        return head;
    }

    // Print function
    void print(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert at head
    Node* insertAtHead(Node* head, int val) {
        Node* temp = new Node(val, head);
        return temp;
    }

    Node* insertAtTail(Node* head, int val) {
        if (head == nullptr) {
            return new Node(val);
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            // we move temp
            temp = temp->next;
        }
        // at this point temp is at the last node
        Node* newNode = new Node(val);
        temp->next = newNode;
        return head;
    }

    // Insert at given k position
    Node* insertAtPosition(Node* head, int k, int val) {
        if (head == nullptr) {
            if (k == 1) {
                return new Node(val);
            } else {
                cout << "Invalid position" << endl;
                return head;
            }
        }

        if (k == 1) {
            // insert at head right!
            Node* newHead = new Node(val, head);
            return newHead;
        }

        int cnt = 0;
        Node* temp = head;
        while (temp != nullptr) {
            cnt++;
            if (cnt == (k - 1)) {
                Node* newNode = new Node(val, temp->next);
                temp->next = newNode;
                break;
            }
            // if cnt not equal to k then move temp
            temp = temp->next;
        }
        return head;
    }

    // Insert an element / newVal before the given value in LL
    Node* insertBeforeValue(Node* head, int newVal, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        // if its insert at head
        if (head->data == val) {
            Node* newNode = new Node(newVal, head);
            return newNode;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == val) {
                Node* newNode = new Node(newVal, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main() {
    vector<int> arr = {12, 2, 4, 5, 8, 4, 15, 21};
    Solution sol;
    Node* head = sol.convertArr2LL(arr);
    // Original LL
    cout << "Original Linked List: " << endl;
    sol.print(head);

    // Insert at head
    cout << "Inserting at the head..." << endl;
    head = sol.insertAtHead(head, 100);
    sol.print(head);

    // Insert at tail
    cout << "Inserting at the tail..." << endl;
    head = sol.insertAtTail(head, 300);
    sol.print(head);

    // Insert at kth position
    int k;
    cout << "Enter the position to insert: " << endl;
    cin >> k;
    cout << "Inserting at " << k << " position..." << endl;
    head = sol.insertAtPosition(head, k, 250);
    sol.print(head);

    // Insert an element/newVal before the given value in LL
    int newVal, ele;
    cout << "Enter the new value to insert..." << endl;
    cin >> newVal;
    cout << "Enter the element in LL before which it has to be inserted..." << endl;
    cin >> ele;
    cout << "Inserting " << newVal << " before " << ele << endl;
    head = sol.insertBeforeValue(head, newVal, ele);
    sol.print(head);

    return 0;
}
