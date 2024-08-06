#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};
/* brute force :O(len)+O(len-K) space:O(1)
Node* removeKthFromEnd(Node* head, int K){
    int cnt =0;
    Node* temp = head;

    while(temp!=nullptr){
        cnt++;
        temp = temp -> next;
    }
    //if cnt == K ie head to be deleted
    if(cnt == K) return head -> next;
    int res = cnt -K;
    temp = head;
    while(temp !=nullptr){
        res--;
        if(res==0){
            break;
        }
        temp = temp -> next;
    }
    Node* delNode= temp -> next;
    temp -> next = temp -> next -> next;
    delete delNode;

    return head;
}
*/

// optimal
Node* removeKthFromEnd(Node* head, int K){
        Node* fast = head;
        for(int i=0;i<K;i++){
            fast = fast -> next;
        }
        Node* slow = head;
        if(fast == nullptr){
            //ie delete head
            return head -> next;
        }

        while( fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }

        Node* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete delNode;

        return head;
}

Node* insertAtEnd(Node* head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        return newNode;
    }
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp ->next;
    }
    temp -> next = newNode;

    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main() {
    Node* head= nullptr;

    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,5);
    head = insertAtEnd(head,7);

    cout<<"original LL "<<endl;
    print(head);

    int K =2;
    cout<<"after deleting the "<<K<<" node"<<endl;
    head = removeKthFromEnd(head,K);
    print(head);

    return 0;
}