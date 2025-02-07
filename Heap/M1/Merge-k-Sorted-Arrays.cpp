#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    vector<int> mergeKArrays(vector<vector<int>>arr, int k){
        vector<int>ans;
        for(int i =0; i<k;i++){
            for(int j = 0; j<k; j++){
                ans.push_back(arr[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
*/



class Node {
public:
    int val, arrPos, valPos;
    Node(int v, int ap, int vp) {
        val = v;
        arrPos = ap;
        valPos = vp;
    }
};

struct myComparator {
    bool operator()(Node &a, Node &b) {
        return a.val > b.val; // Create a Min Heap based on values
    }
};

class Solution {
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        vector<int> ans;
        priority_queue<Node, vector<Node>, myComparator> pq;

        // Insert first element from each array into the heap
        for (int i = 0; i < K; i++) {
            pq.push(Node(arr[i][0], i, 0)); // Node(value, array index, value index)
        }

        // Process the heap until it is empty
        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();

            ans.push_back(node.val); // Add the smallest element to the result

            // If there is another element in the same array, push it into the heap
            int arpos = node.arrPos;
            int vapos = node.valPos;
            if (vapos + 1 < arr[arpos].size()) {
                pq.push(Node(arr[arpos][vapos + 1], arpos, vapos + 1));
            }
        }

        return ans;
    }
};


int main() {
    
    int k;
    cin>>k;

    vector<vector<int>>arr;

    for(int i =0; i<k; i++){
        for(int j = 0; j<k; j++){
            cin>> arr[i][j];
        }
    }

    vector<int>res = sol.mergeKArrays(arr, k);

    for(int i =0; i<res.size(); i++){
        cout<< res[i] <<endl;
    }

    return 0;
}