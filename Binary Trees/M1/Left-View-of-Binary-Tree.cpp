#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution {
public:
    void solve(Node* node, int level, vector<int>& ans) {
        if (node == nullptr) return;

        if (ans.size() == level)
            ans.push_back(node->data);

        solve(node->left, level + 1, ans);
        solve(node->right, level + 1, ans);
    }

    vector<int> leftView(Node* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> ans = sol.leftView(root);

    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
