#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            mpp[x][y].insert(node->val);

            if(node->left){
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right){
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        for(auto p : mpp){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

// Function to insert nodes into a binary tree
TreeNode* insertLevelOrder(vector<int>& arr, int i, int n) {
    if (i >= n || arr[i] == -1) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    TreeNode* root = insertLevelOrder(arr, 0, n);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    for(auto& col : result) {
        for(int val : col) cout << val << " ";
        cout << endl;
    }

    return 0;
}
