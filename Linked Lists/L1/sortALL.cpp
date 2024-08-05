#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to sort the linked list

    /*
    Node *sortList(Node *head)
    {
        vector<int> arr;
        Node *temp = head;

        // Extract values into a vector
        while (temp != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Copy sorted values back to the linked list
        temp = head;
        int j = 0;
        while (temp != nullptr)
        {
            temp->val = arr[j];
            j++;
            temp = temp->next;
        }

        // Return the head of the sorted linked list
        return head;
    }
    */

    // optimal
    Node *findMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted linked lists
    Node *merge2list(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = merge2list(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge2list(l1, l2->next);
            return l2;
        }
    }

    // Function to sort the linked list using merge sort
    Node *sortList(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *mid = findMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = nullptr;

        Node *leftSorted = sortList(left);
        Node *rightSorted = sortList(right);

        return merge2list(leftSorted, rightSorted);
    }

    // Function to print the linked list
    void printList(Node *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Function to create a linked list from a vector of values
    Node *createList(const vector<int> &vals)
    {
        if (vals.empty())
            return nullptr;
        Node *head = new Node(vals[0]);
        Node *current = head;
        for (int i = 1; i < vals.size(); i++)
        {
            current->next = new Node(vals[i]);
            current = current->next;
        }
        return head;
    }
};

int main()
{
    Solution sol;

    // Create a linked list
    vector<int> vals = {4, 2, 1, 3};
    Node *head = sol.createList(vals);

    // Print the original list
    cout << "Original list: ";
    sol.printList(head);

    // Sort the list
    head = sol.sortList(head);

    // Print the sorted list
    cout << "Sorted list: ";
    sol.printList(head);

    return 0;
}
