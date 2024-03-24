#include<bits/stdc++.h>
using namespace std;
// Define the structure for ListNode
struct ListNode {
  int val;
  ListNode* next; 

  ListNode(int x){
    this -> val = x;
    this -> next = NULL;
  }
};


// Define the Solution class
class Solution {
  public: ListNode * middleNode(ListNode * head) {
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast != NULL && fast -> next != NULL) {
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    return slow;
  }
};

// Main function to test the Solution class
int main() {
  // Create a linked list
  ListNode * head = new ListNode(1);
  head -> next = new ListNode(2);
  head -> next -> next = new ListNode(3);
  head -> next -> next -> next = new ListNode(4);
  head -> next -> next -> next -> next = new ListNode(5);

  // Create an object of the Solution class
  Solution solution;

  // Find the middle node of the linked list
  ListNode * middle = solution.middleNode(head);

  // Print the value of the middle node
  std::cout << "The middle node value is: " << middle -> val << std::endl;

  // Free memory by deleting the linked list
  while (head != NULL) {
    ListNode * temp = head;
    head = head -> next;
    delete temp;
  }

  return 0;
}