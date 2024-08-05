#include <iostream>
#include <stack>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

bool isPalindrome(Node* head) {
    if (head == nullptr) return true;

    Node* temp = head;
    stack<int> st;

    // Push all elements of the linked list into the stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Reset temp to head and compare the elements with stack top
    temp = head;
    while (temp != nullptr) {
        if (temp->data != st.top()) {
            return false; // Not a palindrome
        }
        st.pop();
        temp = temp->next;
    }

    return true; // It's a palindrome
}

// Function to insert a new node at the end of the linked list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 2);
    insertEnd(head, 1);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
