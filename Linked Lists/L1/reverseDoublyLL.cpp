#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
public:

    /*  brute force: time:O(2n) space: O(n)
    Node* reverseDLL(Node* head) {   
        // Write your code here  
        Node* temp = head;
        stack<int> st;

        // Traverse the list and push all elements onto the stack
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        // Reassign the values in reverse order
        temp = head;
        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head; 
    }
    */
    // optimized solution: time: O(n) space: O(1)
    Node* reverseDLL(Node* head){
        if(head==nullptr || head -> next == nullptr){
            return head;
        }
        Node* back = nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            back = curr -> prev;
            curr -> prev = curr -> next;
            curr -> next = back;

            //move ahead
            curr = curr -> prev;
        }

        return back -> prev;
    }

    void printDLL(Node* head) {
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
        newNode->prev = temp;
        return head;
    }
};

int main() {
    Solution sol;

    // Create a doubly linked list
    Node* head = nullptr;
    head = sol.insertAtEnd(head, 1);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 4);
    head = sol.insertAtEnd(head, 5);

    cout << "Original DLL: ";
    sol.printDLL(head);

    // Reverse the doubly linked list
    head = sol.reverseDLL(head);

    cout << "Reversed DLL: ";
    sol.printDLL(head);

    return 0;
}
