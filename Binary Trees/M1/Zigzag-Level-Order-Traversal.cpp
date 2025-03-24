#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int d) {
        val = d;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size(); 
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                int index;
                if (leftToRight) {
                    index = i;
                } else {
                    index = size - i - 1; 
                }

                row[index] = front->val;

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            // After each level
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans; // Fix 3: Return ans
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print the result
    for(auto &lev : result){
        for(int i : lev){
            cout<< i << " ";
        }
        cout<< endl;
    }

    return 0;
}
