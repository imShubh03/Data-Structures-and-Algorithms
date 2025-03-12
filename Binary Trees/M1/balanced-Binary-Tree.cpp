#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int d){
        val = d;
        left = right = NULL;
    }
};


/* TC:O(n * n) SC:O(n)
class Solution {
    public:
    int height(TreeNode* root){
        if(root == NULL ) return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == nullptr){
            return true;
        }

        //check the left height and right height
        int lh = height(root -> left);
        int rh = height(root -> right);

        if(abs(lh - rh) > 1) return false;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        if(!left || !right){
            return false;
        }
        return true;
    }
};
*/

class Solution {
    public:
    int dfsHeight(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        int leftH = dfsHeight(root->left);
        if(leftH == -1) return -1;  

        int rightH = dfsHeight(root->right);
        if(rightH == -1) return -1;  

        if(abs(leftH - rightH) > 1) return -1;  
        
        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
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


    bool ans = sol.isBalanced(root);

    if(ans){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


    return 0;
}