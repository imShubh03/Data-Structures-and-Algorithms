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

/* TC:O(n^2) SC:O(n)
class Solution {
public:
    int findMaxPath(TreeNode* root, int &maxSum) {
        if (root == NULL) return 0; // Base case: Empty node contributes 0 to path sum

        // Recursively find the maximum path sum in left and right subtrees
        int leftSum = findMaxPath(root->left, maxSum);
        int rightSum = findMaxPath(root->right, maxSum);

        // Case 1: Only the node itself (Exclude left and right)
        int onlyNode = root->val;

        // Case 2: Node + Left Subtree Path
        int nodeWithLeft = root->val + leftSum;

        // Case 3: Node + Right Subtree Path
        int nodeWithRight = root->val + rightSum;

        // Case 4: Node + Left Subtree + Right Subtree (Forms a "V" shape, a turning point)
        int nodeWithBoth = root->val + leftSum + rightSum;

        // Update the global maxSum with the best case found so far
        maxSum = max({maxSum, onlyNode, nodeWithLeft, nodeWithRight, nodeWithBoth});

        // Return the best path sum **that can be extended upwards** (singlePath)
        return max(onlyNode, max(nodeWithLeft, nodeWithRight));
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize to the smallest possible value
        findMaxPath(root, maxSum);
        return maxSum;
    }
};
*/

// TC:O(n)  SC:O(n)
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
