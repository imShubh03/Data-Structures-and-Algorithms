#include <bits/stdc++.h>
using namespace std;

/* brute : time:O(n^2) space:O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt > (n / 3) && find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                ans.push_back(nums[i]); // Add only if not already in ans
            }
        }
        return ans;
    }
};
*/

/* better time:O(n) space:O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n = nums.size();
        for(int i =0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            if(it.second > (n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
*/



int main() {
    Solution sol;
    int n;
    cin>>n;
    
    vector<int> nums(n); 

    for(int i =0; i<n; i++){
        cin>>nums[i];
    }
    
    vector<int> result = sol.majorityElement(nums);
    
    // Output the result
    for (int x : result) {
        cout << x << " ";
    }
    
    cout << endl;
    
    return 0;
}
