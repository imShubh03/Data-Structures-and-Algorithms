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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            int minLevIdx = q.front().second;
            int first = 0, last = 0;

            for(int i = 0; i < size; i++) {
                auto nodePair = q.front();
                q.pop();
                
                TreeNode* node = nodePair.first;
                int currIdx = nodePair.second - minLevIdx;

                if(i == 0) first = currIdx;
                if(i == size - 1) last = currIdx;

                if(node->left)
                    q.push({node->left, currIdx * 2 + 1});
                
                if(node->right)
                    q.push({node->right, currIdx * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << "Maximum Width: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
