#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    //constructor
    TreeNode(int d){
        this -> val = d;
        this -> left = NULL;
        this ->right=NULL;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0 ;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        int ans= max(left,right) + 1;

        return ans;
        
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Maximum depth of the tree: " << depth << endl;

    // Remember to free memory allocated for the tree nodes
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
