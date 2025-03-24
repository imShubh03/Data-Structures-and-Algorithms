#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> serialize(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (node) {
                ans.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }

    Node* deSerialize(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        
        int i = 1;
        while (!q.empty() && i < n) {
            Node* node = q.front();
            q.pop();
            
            if (i < n && arr[i] != -1) {
                node->left = new Node(arr[i]);
                q.push(node->left);
            }
            i++;

            if (i < n && arr[i] != -1) {
                node->right = new Node(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

void printLevelOrder(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        if (node) {
            cout << node->data << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "-1 ";
        }
    }
}

int main() {
    Solution sol;
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> serializedTree = sol.serialize(root);
    for (int val : serializedTree) {
        cout << val << " ";
    }
    cout << endl;

    Node* deserializedRoot = sol.deSerialize(serializedTree);
    
    printLevelOrder(deserializedRoot);
    cout << endl;

    return 0;
}
