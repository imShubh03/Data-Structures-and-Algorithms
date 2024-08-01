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
    Node* addTwoNumbers(Node* head1, Node* head2) {
        // Create a dummy node to serve as the starting point
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        Node* temp1 = head1;
        Node* temp2 = head2;
        int carry = 0;

        // Traverse both lists
        while (temp1 != nullptr || temp2 != nullptr) {
            // Initialize sum with carry
            int sum = carry;

            // If temp1 exists, add its data to sum
            if (temp1) {
                sum += temp1->data;
            }

            // If temp2 exists, add its data to sum
            if (temp2) {
                sum += temp2->data;
            }

            // Create a new node which stores sum modulo 10
            Node* newNode = new Node(sum % 10);

            // Find the carry
            carry = sum / 10;

            // Link the current node with newNode
            curr->next = newNode;

            // Move the current pointer
            curr = curr->next;

            // Move temp1 and temp2 to the next nodes if they exist
            if (temp1) {
                temp1 = temp1->next;
            }
            if (temp2) {
                temp2 = temp2->next;
            }
        }

        // If there's a leftover carry, create a new node for it
        if (carry) {
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }

        // Return the next of dummy node, which is the head of the result list
        return dummy->next;
    }

    void printList(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
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

    // Create two numbers as linked lists
    Node* head1 = nullptr;
    head1 = sol.insertAtEnd(head1, 2);
    head1 = sol.insertAtEnd(head1, 4);
    head1 = sol.insertAtEnd(head1, 3);

    Node* head2 = nullptr;
    head2 = sol.insertAtEnd(head2, 5);
    head2 = sol.insertAtEnd(head2, 6);
    head2 = sol.insertAtEnd(head2, 4);

    cout << "Number 1: ";
    sol.printList(head1);

    cout << "Number 2: ";
    sol.printList(head2);

    // Add the two numbers
    Node* result = sol.addTwoNumbers(head1, head2);

    cout << "Result: ";
    sol.printList(result);

    return 0;
}
  