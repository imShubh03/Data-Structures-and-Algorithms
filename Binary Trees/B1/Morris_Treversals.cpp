#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;

        while (curr != NULL) {
            // Cases here: if left does not exist
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } 
            else {
                TreeNode* prev = curr->left;

                // Cases here: find rightmost node in left subtree or thread exists
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                // Cases here: if thread is not created
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } 
                // Cases here: if thread exists, remove it and process current node and move to right
                else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

class Solution {
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr != NULL) {
            // 2 cases: if curr->left exists or not

            // If left does not exist, add the root and move to the right
            if (curr->left == NULL) {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            // If left exists, find the rightmost node of the left subtree
            else {
                TreeNode* prev = curr->left;

                // Move to the rightmost node until it's NULL and should not point to curr
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                // At the rightmost node, there are 2 cases: prev->right is NULL or not NULL

                if (prev->right == NULL) {
                    // We need to create a thread
                    prev->right = curr;
                    // At this moment, add the value to the answer
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    // If a thread is already created, remove it and move to the right
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};
    

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = sol.inorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
