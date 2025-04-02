#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/*
class Solution {
    public:
    void preorder(Node* root, vector<int>& nodes) {
        if(root == NULL) return;
        nodes.push_back(root->data);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

    int kthLargest(Node* root, int k) {
        vector<int> nodes;
        preorder(root, nodes);
        sort(nodes.begin(), nodes.end());
        int n = nodes.size();
        return nodes[n - k]; // Corrected index
    }
};
*/

/*
class Solution {
    public:
    void inorder(Node* root, vector<int>&nodes){
        if(root == NULL) return;
        inorder(root -> left, nodes);
        nodes.push_back(root -> data);
        inorder(root -> right, nodes);
    }
      int kthLargest(Node *root, int k) {
          // Your code here
        vector<int>nodes;
        inorder(root, nodes);
        int n = nodes.size();
        return nodes[n-k];
    }
};
*/

class Solution {
    public:
    void inorder(Node* root, int k, int &cnt, int &ans){
          //reverse inorder for largest
        if(root == NULL) return;
        inorder(root -> right, k, cnt, ans);
        cnt++;
        if(cnt == k){
            ans = root -> data;
            return;
        }
        inorder(root ->left, k, cnt, ans);
    }
    int kthLargest(Node *root, int k) {
          // Your code here
        int cnt = 0;
        int ans = -1;
        inorder(root, k, cnt, ans);
        return ans;
    }
};

Node* insertIntoBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    Solution sol;
    Node* root = NULL;

    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = insertIntoBST(root, val);
    }

    int k;
    cin >> k;

    cout << sol.kthLargest(root, k) << endl;

    return 0;
}
