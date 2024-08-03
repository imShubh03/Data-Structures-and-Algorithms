#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    /*  brute: time:O(n 2 logn) depend on map   space:O(n)
    Node* detectCycle(Node* head) {
        // Unordered map to track visited nodes
        unordered_map<Node*, int> mp;
        Node* temp = head;

        // Traverse the list
        while (temp != nullptr) {
            // If the node is found in the map, cycle detected
            if (mp.count(temp) != 0) {
                return temp; // returning the node where cycle starts
            }
            // If not, add the node to the map
            mp[temp] = 1;
            temp = temp->next;
        }

        // No cycle found
        return nullptr;
    }
    */

    // Floyd's cycle-finding algorithm: time:O(n) space:O(1)
    Node* detectCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return nullptr;
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

    // Create a singly linked list with a cycle
    Node* head = nullptr;
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 0);
    head = sol.insertAtEnd(head, 10);
    head = sol.insertAtEnd(head, 17);
    head = sol.insertAtEnd(head, 44);

    // Creating a cycle: connecting last node to the second node
    head->next->next->next = head->next->next;

    // Detect the cycle
    Node* cycleStart = sol.detectCycle(head);
    if (cycleStart != nullptr) {
        cout << "Cycle detected at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
