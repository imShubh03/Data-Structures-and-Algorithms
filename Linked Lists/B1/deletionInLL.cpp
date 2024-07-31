#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int d){
        data = d;
        next = nullptr;
    }
};

class Solution{
    public:
    Node* convertArr2LL(vector<int>&arr){
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* mover = head;

        for(int i =1;i<n;i++){
            Node* temp = new Node(arr[i]);
            mover -> next = temp;
            //update mover
            mover = mover -> next;
        }
        return head;
    }

    //print function
    void print(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    //delete from head
    Node* removeHead(Node* head){
        if(head == nullptr) return head;
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    //delete from tail
    Node* removeTail(Node* head){
        if(head == nullptr || head -> next ==nullptr) return nullptr;

        Node* temp = head;
        //i have to stop at last sec node
        while(temp -> next -> next != nullptr){
            temp = temp -> next;
        }
        //delete last node
        delete (temp -> next);
        temp -> next = nullptr;

        return head;
    }

    //remove at k position
    Node* removeAtK(Node* head, int k){
        if(head == nullptr || k<0) return head;

        //head is to be removed
        if(k ==1){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        int cnt =0;
        Node* temp = head;
        Node* prev = nullptr;
        while(temp!=nullptr){
            cnt++;
            if(cnt == k){
                prev -> next = prev -> next -> next;
                delete temp;
                break;
            }

            prev = temp;
            temp = temp -> next;
            
        }
        return head;
    }

    //remove the elem with given val
    Node* removeElem(Node* head, int val){
        if(head == nullptr) return head;

        //head is to be removed
        if(head -> data == val){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while(temp!=nullptr){
            if(temp -> data == val){
                prev -> next = prev -> next -> next;
                delete temp;
                break;
            }

            prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};

int main() {
    vector<int>arr ={12,2,4,5,8,4,15,21};
    Solution sol;
    Node* head = sol.convertArr2LL(arr);
    //original LL
    cout<<"Original Linked List: "<<endl;
    sol.print(head);

    //remove head
    head = sol.removeHead(head);
    cout<<"deleting the head..."<<endl;
    sol.print(head);

    //remove tail
    head = sol.removeTail(head);
    cout<<"deleting the tail..."<<endl;
    sol.print(head);

    //remove at k position
    int k;
    cout<<"enter position to delete..."<<endl;
    cin>>k;
    head = sol.removeAtK(head,k);
    cout<<"deleting at "<<k<<" position..." <<endl;
    sol.print(head);

    //remove the eleme in LL with given value
    int val;
    cout<<"enter value to delete..."<<endl;
    cin>>val;
    head = sol.removeElem(head,val);
    cout<<"deleting "<<val<<" from LL..."<<endl;
    sol.print(head);



    return 0;
}