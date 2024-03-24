#include<bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
// traversing link list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// len of link list
int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;

        temp = temp->next;
    }
    return len;
}

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d); // crreating a new node
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d); // crreating a new node
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << getlength(head) << endl;

    insertathead(head, 11);
    print(head);

    insertathead(head, 16);
    print(head);

    insertattail(tail, 25);
    print(head);

    return 0;
}