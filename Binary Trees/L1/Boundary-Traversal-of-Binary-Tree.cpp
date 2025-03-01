#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int d){
        val = d;
        left = right = nullptr;
    }
};

class Solution{
    private:
    bool isLeaf(Node* root){
        return !root -> left && !root -> right;
    }
    void addLeftBoundary(Node* root, vector<int>&ans){
        Node* curr = root -> left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr -> val);
            if(curr -> left) curr = curr -> left;
            else curr = curr -> right;
        }
    }
    void addLeaves(Node* root, vector<int>&ans){
        //preorder traversal
        if(isLeaf(root)){
            ans.push_back(root -> val);
            return;
        }
        if(root -> left) addLeaves(root -> left, ans);
        if(root -> right) addLeaves(root -> right, ans);
    }
    void addRightBoundary(Node* root, vector<int>&ans){
        Node* curr= root -> right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr -> val);
            if(curr -> right) curr = curr -> right;
            else curr = curr -> left;
        }
        reverse(temp.begin(), temp.end());
        
        ans.insert(ans.end(), temp.begin(), temp.end());
    }

    public:
    vector<int>boundaryTraversal(Node* root){
        vector<int>ans;
        if(root == NULL) return ans;
        //push the root if its not leaf
        if(!isLeaf(root)) ans.push_back(root -> val);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int>ans = sol.boundaryTraversal(root);
    
    for (int num : ans) cout << num << " ";

    return 0;
}