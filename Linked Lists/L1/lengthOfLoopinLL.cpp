#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to insert a node at the end of the linked list
    Node* insertAtEnd(Node *head, int val) {
        Node *newNode = new Node(val);
        if (!head) return newNode;

        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }

    /*
    int detectCycleLength(Node *head) {
        unordered_map<Node*, int> nodeMap;
        Node *temp = head;
        int index = 0;

        // Traverse the list and check for a cycle
        while (temp != nullptr) {
            // If the node is already in the map, cycle is detected
            if (nodeMap.count(temp) != 0) {
                return index - nodeMap[temp]; // Length of the cycle
            }

            // Store the node in the map with its index
            nodeMap[temp] = index;
            temp = temp->next;
            index++;
        }  
        return 0; // No cycle detected
    }
    */
    // Optimized version of detectCycleLength using Floyd's Tortoise and Hare algorithm
    int getLen(Node* slow, Node* fast) {
        int cnt =1;
        fast = fast -> next;
        while(fast != slow){
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }
    int detectCycleLength(Node *head) {
        if (!head ||!head->next) return 0;
        Node* slow = head;
        Node* fast = head;

        while(fast !=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return getLen(slow,head);
            }
        }
        return 0;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    Node* head = nullptr;
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 0);
    head = sol.insertAtEnd(head, 10);
    head = sol.insertAtEnd(head, 17);
    head = sol.insertAtEnd(head, 44);

    // Creating a cycle: connecting the last node to the third node (0)
    head->next->next->next->next->next->next = head->next->next;

    int cycleLength = sol.detectCycleLength(head);
    if (cycleLength > 0) {
        cout << "Cycle detected with length: " << cycleLength << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
