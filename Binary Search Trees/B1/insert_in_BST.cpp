#include<bits/stdc++.h>

using namespace std;
// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val){
        // base case
        if (root == nullptr){
            TreeNode *ans = new TreeNode(val);
            return ans;
        }
        if (val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        else{
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

// Function to print inorder traversal of a binary tree
void inorderTraversal(TreeNode *root){
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()){
        int levelSize = q.size();
        vector<int> levelValues;

        for (int i = 0; i < levelSize; ++i){
            TreeNode *temp = q.front();
            q.pop();

            levelValues.push_back(temp->val);

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
        ans.push_back(levelValues);
    }
    return ans;
}

int main(){
    Solution solution;
    TreeNode *root = NULL; // Initialize an empty BST

    // Insert values into the BST
    root = solution.insertIntoBST(root, 5);
    solution.insertIntoBST(root, 3);
    solution.insertIntoBST(root, 8);
    solution.insertIntoBST(root, 2);
    solution.insertIntoBST(root, 4);
    solution.insertIntoBST(root, 6);
    solution.insertIntoBST(root, 9);

    

    cout << "level order traversal" << endl;
    vector<vector<int>> result = levelOrder(root);

    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    /*
// Print inorder traversal of the BST
    std::cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    std::cout << std::endl;
    */

    return 0;
}



