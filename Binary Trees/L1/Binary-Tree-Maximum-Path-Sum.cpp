#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    int maxPathDown(Node* node, int &maxi) {
        if(node == nullptr) return 0;

        int leftSum = max(0, maxPathDown(node -> left, maxi));
        int rightSum = max(0, maxPathDown(node -> right, maxi));

        maxi = max(maxi, leftSum + rightSum + node -> data); 

        return node -> data + max(leftSum, rightSum);
    }

    int maxPathSum(Node* root){
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
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
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}
