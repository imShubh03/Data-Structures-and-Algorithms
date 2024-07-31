#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:

    /*  brute : time:O(2n) space:O(1)
    int getLen(Node* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }

    Node* findMiddle(Node* head) {
        int len = getLen(head);
        int ans = len / 2;
        Node* temp = head;
        int cnt = 0;
        while (cnt < ans) {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
    */

    //optimised
    Node* findMiddle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while (fast!=nullptr && fast ->next != nullptr){
            slow = slow ->next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    void printSLL(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* insertAtEnd(Node* head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            return newNode;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
};

int main() {
    Solution sol;

    // Create a singly linked list
    Node* head = nullptr;
    head = sol.insertAtEnd(head, 1);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 4);
    head = sol.insertAtEnd(head, 5);

    cout << "Original SLL: ";
    sol.printSLL(head);

    // Find the middle of the singly linked list
    Node* middle = sol.findMiddle(head);
    
    cout << "Middle element is " << middle->data << endl;
    return 0;
}
