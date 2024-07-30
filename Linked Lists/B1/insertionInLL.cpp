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
    head = sol.insertAtHead(head, 10);
    sol.print(head);

    return 0;
}
