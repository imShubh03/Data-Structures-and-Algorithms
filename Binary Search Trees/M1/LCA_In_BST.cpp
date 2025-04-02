#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

/*
class Solution {
public:
    bool findPath(TreeNode* root, vector<TreeNode*>& path, int target) {
        if (!root) return false;

        path.push_back(root);

        if (root->val == target) return true;

        if ((root->left && findPath(root->left, path, target)) || 
            (root->right && findPath(root->right, path, target))) {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;

        if (!findPath(root, p1, p->val) || !findPath(root, p2, q->val)) {
            return NULL;
        }

        TreeNode* lca = NULL;

        for (int i = 0; i < min(p1.size(), p2.size()); i++) {
            if (p1[i] == p2[i]) {
                lca = p1[i];
            } else {
                break;
            }
        }

        return lca;
    }
};
*/

class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        int data = root -> val;

        if(data < p -> val && data < q -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }

        if(data > p -> val && data > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left->right->left, root->left->right->right);
    cout << "LCA: " << lca->val << endl; // Output: LCA: 4

    return 0;
}