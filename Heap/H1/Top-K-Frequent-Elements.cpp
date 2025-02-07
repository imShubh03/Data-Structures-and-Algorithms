#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> mp;
        
        // Count frequency of each number
        for (int &it : nums) {
            mp[it]++;
        }

        vector<pair<int, int>> freq;

        // Store frequency and element pairs in the vector
        for (auto &it : mp) {
            freq.push_back({it.second, it.first});
        }

        // Sort the vector based on frequency in descending order
        sort(freq.rbegin(), freq.rend());

        // Extract the k most frequent elements
        for (int i = 0; i < k; i++) {
            res.push_back(freq[i].second);
        }

        return res;
    }
};
*/

class Solution {
public:
    typedef pair<int, int> P;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> mp;
        
        // Count frequency of each number
        for (int &it : nums) {
            mp[it]++;
        }

        // Define min heap
        priority_queue<P, vector<P>, greater<P>> pq; 

        // Push elements in min-heap, maintaining size of k
        for (auto &it : mp) {
            int val = it.first;
            int freq = it.second;

            pq.push({freq, val});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract elements from the min-heap and fill the result vector
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};



int main() {
    int n, k;
    cin>>n>>k;

    vector<int>nums(n);

    for(int i =0; i<n; i++){
        cin>> nums[i];
    }

    Solution sol;
    vector<int>ans = sol.topKFrequent(nums, k);

    for(int i =0; i<ans.size(); i++){
        cout<<ans[i] << " ";
    }

    return 0;
}