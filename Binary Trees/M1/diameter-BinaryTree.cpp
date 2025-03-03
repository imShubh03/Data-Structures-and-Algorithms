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

/*  TC:O(n^2)
class Solution{
    public:
    int maxi = 0;

    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(Node* root){
        //base case
        if(root == nullptr) return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        maxi = max(maxi, lh + rh);

        diameterOfBinaryTree(root -> left);
        diameterOfBinaryTree(root -> right);
    }
};
*/


class Solution {
    public:
        int height(TreeNode* root, int &diameter){
            if(root == nullptr) return 0;
            int lh = height(root -> left, diameter);
            int rh = height(root -> right, diameter);
            diameter = max(diameter, lh + rh);
    
            return 1 + max(lh, rh);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            if(root == nullptr) return 0;
    
            int diameter = 0;
            height(root, diameter);
    
            return diameter;
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
    int ans = sol.diameterOfBinaryTree(root);
    cout<<ans;

    return 0;
}