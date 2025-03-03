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

//DFS solution  TC:O(n) SC:O(n)(skew tree)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0 ;
        }
        int leftSide = maxDepth(root -> left);
        int rightSide = maxDepth(root -> right);

        int ans= max(leftSide,rightSide) + 1;  //1 for curr node and then add with max from left and right

        return ans;
        
    }
};

/*  BFS solution
class Solution {
    public:
    int maxDepth(TreeNode* root) {
        // Fix: Handle empty tree case
        if (root == nullptr) return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return depth;
    }
};
*/

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
    

    return 0;
}
