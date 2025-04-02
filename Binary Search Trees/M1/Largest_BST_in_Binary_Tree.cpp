#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};

/*
class Solution {
public:
    // Check if a tree is a valid BST
    bool isBST(TreeNode* root, int minVal, int maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
    }

    // Count number of nodes in a tree
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Find the largest BST subtree size
    int largestBST(TreeNode* root) {
        if (!root) return 0;
        if (isBST(root, INT_MIN, INT_MAX)) return countNodes(root);
        return max(largestBST(root->left), largestBST(root->right));
    }
};
*/

class NodeVal {
    public:
        int minNode, maxNode, maxSize;
        NodeVal(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
    };
    
class Solution {
public:
    NodeVal helper(TreeNode* root) {
        if (!root) {
            return NodeVal(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // If it's a BST
        if (root->val > left.maxNode && root->val < right.minNode) {
            return NodeVal(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }

        // If not a BST, return max of left and right
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(TreeNode* root) {
        return helper(root).maxSize;
    }
};
    

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);  // This makes it not a BST

    Solution sol;
    cout << "Size of Largest BST: " << sol.largestBST(root) << endl;
    return 0;
}
