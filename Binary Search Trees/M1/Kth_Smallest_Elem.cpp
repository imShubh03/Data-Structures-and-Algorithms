#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

/* Brute TC :O(n) + O(nlogn)  SC:O(n)
class Solution {
public:
    void storeNodes(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) return;
        nodes.push_back(root->val);
        storeNodes(root->left, nodes);
        storeNodes(root->right, nodes);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        storeNodes(root, nodes);
        sort(nodes.begin(), nodes.end());
        return nodes[k-1];
    }
};
*/

/* BETTER  TC:O(n)  SC:O(n)
class Solution {
    public:
    void inOrder(TreeNode* root, vector<int>&inorder){
        if(root == NULL) return;

        inOrder(root -> left, inorder);
        inorder.push_back(root -> val);
        inOrder(root -> right, inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        inOrder(root, inorder);
        return inorder[k-1];
    }
};
*/

// OPTIMAL  TC:O(n) SC = O(1)(not considering recur stack space)
class Solution {
    public:
    void inorder(TreeNode* root, int &cnt, int k, int &ans){

        if(root == NULL) return;

        inorder(root -> left, cnt, k, ans);

        cnt++;

        if(cnt == k){
            ans = root -> val;
            return;
        }
        inorder(root -> right, cnt, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        inorder(root, cnt, k, ans);
        return ans;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = NULL;

    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = insertIntoBST(root, val);
    }

    int k;
    cin >> k;

    cout << sol.kthSmallest(root, k) << endl;

    return 0;
}
