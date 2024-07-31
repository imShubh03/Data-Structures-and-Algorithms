#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }

    Node(int d, Node* nextNode, Node* prevNode){
        data = d;
        next = nextNode;
        prev = prevNode;
    }
};

class Solution{
    public:

    //converting the given arr to LL
    Node* convertArr2DLL(vector<int>&arr){
        int n = arr.size();
        //create a head
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i =1;i<n;i++){
            Node* temp = new Node(arr[i],nullptr,prev);
            prev -> next = temp;
            prev = prev -> next;
        }
        return head;
    }

    //printing the LL
    void printDLL(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    //delete the headof LL
    Node* deleteHead(Node* head){
        //base case if no ele or single elem then return null
        if(head == nullptr || head -> next == nullptr){
            return nullptr;
        }

        //rest case
        Node* prev = head;
        head = head -> next;
        head -> prev = nullptr;
        prev -> next = nullptr;
        delete prev;

        return head;
    }

    //delete the tail of LL
    Node* deleteTail(Node* head){
        //base case if no ele or single elem then return null
        if(head == nullptr || head -> next == nullptr){
            return nullptr;
        }

        Node* tail = head;
        while(tail -> next != nullptr){
            tail = tail -> next;
        }

        Node* back = tail -> prev;
        back -> next = nullptr;
        tail -> prev = nullptr;
        delete tail;

        return head;
    }

    //remove at k position
    Node* removeAtKthPos(Node* head, int k){
        //base case if head = null return null
        if(head == nullptr || k <= 0){
            return nullptr;
        }

        //reach at the kth posti
        int cnt =0;
        Node* temp = head;
        while(temp != nullptr){
            cnt++;
            if(cnt == k) break;
            temp = temp -> next;
        }

        //here at the kth node
        Node* back = temp -> prev;
        Node* front = temp -> next;

        //all casses
        if((back == nullptr)&&(front == nullptr)){
            //we have single ele so delete that
            delete temp;
            return nullptr;
        }
        else if(back == nullptr){
            //delete at the head
            return deleteHead(head);
        }
        else if(front == nullptr){
            //delete at the tail
            return deleteTail(head);
        }

        //delete at kth position
        back -> next = front;
        front -> prev = back;
        temp -> next = nullptr;
        temp -> prev = nullptr;
        delete temp;

        return head;
    }

    //deleting the given node
    Node* removeNode(Node* head, int val) {
        // Case when the list is empty
        if (head == nullptr) return head;

        Node* temp = head;

        // Traverse to find the node with the given value
        while (temp != nullptr && temp->data != val) {
        temp = temp->next;
        }

        // Node with the given value not found
        if (temp == nullptr) return head;

        // If the node to be deleted is the head node
        if (temp == head) {
            head = temp->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return head;
        }
        
        // If the node to be deleted is not the head node
        Node* front = temp->next;
        Node* back = temp->prev;

        if (front != nullptr) {
            front->prev = back;
        }
        if (back != nullptr) {
            back->next = front;
        }

        delete temp;
        return head;
}

};

int main() {
    Solution sol;
    vector<int> arr = {12, 2, 4, 5, 8, 4, 15, 21};
    cout<<"the original DLL..."<<endl;
    Node* head = sol.convertArr2DLL(arr);
    sol.printDLL(head);

    cout<<"deleting the head of DLL..."<<endl;
    head = sol.deleteHead(head);
    sol.printDLL(head);

    cout<<"deleting the tail of DLL..."<<endl;
    head = sol.deleteTail(head);
    sol.printDLL(head);

    //remove at k position
    int k;
    cout<<"enter position to delete..."<<endl;
    cin>>k;
    head = sol.removeAtKthPos(head,k);
    cout<<"deleting at "<<k<<" position..." <<endl;
    sol.printDLL(head);

    //delete the given node
    int val;
    cout<<"enter value to delete..."<<endl;
    cin>>val;
    head = sol.removeNode(head,val);
    cout<<"deleting "<<val<<" from DLL..."<<endl;
    sol.printDLL(head);

    return 0;
}