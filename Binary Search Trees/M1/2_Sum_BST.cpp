#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};


class Solution {
    public:
    void inOrder(TreeNode* root, vector<int>&nodes){
        if(!root) return;

        inOrder(root -> left, nodes);
        nodes.push_back(root -> val);
        inOrder(root -> right, nodes);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>nodes;
        inOrder(root, nodes);

        int l =0; 
        int r = nodes.size() -1;

        while(l < r){
            int sum = nodes[l] + nodes[r];

            if(sum == k){
                return true;
            }
            else if(sum  > k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    Solution sol;
    int target = 9;
    cout << (sol.findTarget(root, target) ? "Yes" : "No") << endl;

    return 0;
}
