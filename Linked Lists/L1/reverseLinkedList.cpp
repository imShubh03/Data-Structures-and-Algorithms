#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node (int d){
        data = d;
        next = nullptr;
    }
};

class Solution {
public:

    /* brute force time:O(2n) space:O(n)
    Node* reverseSLL(Node* head) {   
        // Stack to store the data of the nodes
        stack<int> st;
        Node* temp = head;

        // Push all the node data onto the stack
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        // Pop the data from the stack and assign it back to the nodes
        temp = head;
        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head; 
    }
    */

    // iterative time: O(n) space:O(1)
    Node* reverseSLL(Node* head){
        if(head == nullptr || head -> next ==nullptr){
            return head;
        }
        Node* back = nullptr;
        Node* curr = head;

        while(curr!=nullptr){
            Node* front = curr -> next;
            curr -> next =back;
            back = curr;
            curr = front;
        }
        return back;
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
    head = sol.insertAtEnd(head, 7);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 4);
    head = sol.insertAtEnd(head, 23);

    cout << "Original SLL: ";
    sol.printSLL(head);

    // Reverse the singly linked list
    head = sol.reverseSLL(head);

    cout << "Reversed SLL: ";
    sol.printSLL(head);

    return 0;
}
