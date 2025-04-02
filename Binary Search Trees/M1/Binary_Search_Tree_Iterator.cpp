#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, *right;

    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};

/*
class BSTIterator {
    vector<int> inorderNodes;
    int index;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderNodes.push_back(root->val);
        inorder(root->right);
    }

    public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        index = 0;
    }

    int next() {
        return inorderNodes[index++];
    }

    bool hasNext() {
        return index < inorderNodes.size();
    }
};
*/

class BSTIterator {
    public:
    stack<TreeNode*> stk;

    void pushAllLeft(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* curr = stk.top();
        stk.pop();
        pushAllLeft(curr->right); // Push all left children of the right subtree
        return curr->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};
    

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);
    
    cout << it.next() << " ";  // 3
    cout << it.next() << " ";  // 7
    cout << it.hasNext() << " "; // 1 (true)
    cout << it.next() << " ";  // 9
    cout << it.next() << " ";  // 15
    cout << it.next() << " ";  // 20
    cout << it.hasNext();   // 0 (false)

    return 0;
}
