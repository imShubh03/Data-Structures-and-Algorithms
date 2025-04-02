#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left, *right;

    TreeNode(int d){
        val = d;
        left = right = nullptr;
    }
};
void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
    if (root == NULL) return;
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
}

/*
class Solution{
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        vector<TreeNode*>nodes;
        inorder(root, nodes);
        int n = nodes.size();
        for(int i = 0; i < n-1; i++){
            if(nodes[i] == p){
                return nodes[i+1];
            }
        }
        return NULL;
    }
};
*/

/*
class Solution {
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        inorder(root, p, successor);
        return successor;
    }

    void inorder(TreeNode* root, TreeNode* p, TreeNode* &successor) {
        if (!root) return;

        inorder(root->left, p, successor);

        if (successor == nullptr && root->val > p->val) {
            successor = root;
            return;
        }

        inorder(root->right, p, successor);
    }
};
*/

class Solution {
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        while (root) {
            if (p->val < root->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return successor;
    }
};


int main() {
    
    Solution sol;
    
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);

    TreeNode* target = root->left->right; // 6 
    TreeNode* successor = sol.inorderSuccessor(root, target);

    cout << successor -> val;

    return 0;
}