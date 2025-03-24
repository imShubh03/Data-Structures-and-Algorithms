#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a tree node
    TreeNode(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution{
    public:
    // In-order Traversal (Left, Root, Right)
    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    // Pre-order Traversal (Root, Left, Right)
    void preOrderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    // Post-order Traversal (Left, Right, Root)
    void postOrderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
};

/*
//iterative code
class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* node = root;

        while(true){
            if(node != nullptr){
                st.push(node);
                node = node-> left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node -> val);
                node = node -> right;
            }
        }
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) return ans;
        stack<TreeNode *>st;

        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node -> val);

            if(node -> right != nullptr) 
                st.push(node-> right);

            if(node -> left != nullptr)
                st.push(node -> left);
            
        }
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                if (!temp) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return ans;
    }            
}
*/
int main() {
    // Create individual nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;

    // Perform in-order traversal
    cout << "In-order Traversal is...";
    sol.inOrderTraversal(root);
    cout << endl;

    // Perform pre-order traversal
    cout << "Pre-order Traversal is...";
    sol.preOrderTraversal(root);
    cout << endl;

    // Perform post-order traversal
    cout << "Post-order Traversal is...";
    sol.postOrderTraversal(root);
    cout << endl;

    return 0;
}
