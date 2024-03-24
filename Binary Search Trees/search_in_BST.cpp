#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* right; 
    TreeNode* left;
    TreeNode (int x){
        this -> val = x;
        this -> right = NULL;
        this -> left = NULL;
    }
};
class Solution{
    TreeNode* insertintoBST(TreeNode* root , int val){
        if(root == NULL){
            TreeNode* ans = new TreeNode(val);
            return ans;
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
    TreeNode* searchintoBST(TreeNode* root , int val){
        if(root == NULL){
            return 0;
        }
        if( root -> data == val){
            return root ;
        }
        if(root -> data > val){
            return searchintoBST(root -> left, val);
        }else{
            return searchintoBST(root -> right,val);
        }
    }
};

int main(){
    Solution solution;
    TreeNode* root == NULL;
    root = solution.insertintoBST(root,21);
    solution.insertIntoBST(root, 10);
    solution.insertIntoBST(root, 50);
    solution.insertIntoBST(root, );
    solution.insertIntoBST(root, 4);
    solution.insertIntoBST(root, 6);
    solution.insertIntoBST(root, 9);
    return 0;
}