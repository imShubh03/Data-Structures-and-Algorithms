#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = nullptr;
    }
};

class Solution{
    public:
    vector<int> bottomView(Node *root){
        vector<int>ans;

        if(root == nullptr) 
            return ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q;

        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            mp[line] = node -> data;

            if(node -> left)
                q.push({node -> left, line -1});

            if(node -> right)
                q.push({node -> right, line + 1});
            
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
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

    return 0;
}