#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

/*  TC : O(2n)  SC:O(2n)
class Solution {
public:
    bool getPath(TreeNode* node, TreeNode* target, vector<TreeNode*>& path) {
        if (node == nullptr) return false;

        path.push_back(node);

        if (node == target)
            return true;

        if (getPath(node->left, target, path) || getPath(node->right, target, path))
            return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        if (!getPath(root, p, path1) || !getPath(root, q, path2))
            return nullptr;

        TreeNode* lca = nullptr;
        int minLength = min(path1.size(), path2.size());

        for (int i = 0; i < minLength; i++) {
            if (path1[i] == path2[i])
                lca = path1[i];
            else
                break;
        }
        return lca;
    }
};
*/

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            //base case
            if(root == nullptr || root == p || root == q){
                return root;
            }
            TreeNode* left = lowestCommonAncestor(root -> left, p, q);
            TreeNode* right = lowestCommonAncestor(root -> right, p, q);

            if(left == nullptr){
                return right;
            }
            else if(right == nullptr){
                return left;
            }
            else{
                return root;
            }
        }
    };

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* p = root->left->left;  // Node 4
    TreeNode* q = root->left->right; // Node 5

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "LCA: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
