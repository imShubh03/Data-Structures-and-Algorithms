#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class Solution{
    public:
    bool isSameTree(Node* p, Node* q){
        
        if(p == nullptr || q == nullptr){
            return p == q;
        }
        return (p -> data == q -> data) && 
            isSameTree(p -> left, q ->left) && 
            isSameTree(p ->right, q ->right);
    }
};
int main() {
    
    Node* root1= new Node(1);
    root1 -> left = new Node(2);
    root1 -> right = new Node(3);

    Node* root2 = new Node(1);
    root2 -> left = new Node(2);
    root2 -> right = new Node(3);

    Solution sol;
    bool ans = sol.isSameTree(root1, root2);
    cout<< ans <<endl;

    return 0;
}