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

//optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el1 = INT_MIN, el2 = INT_MIN;  // Initialize with a value not present in the array
        int cnt1 = 0, cnt2 = 0;

        // First pass to find potential candidates
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (el1 == nums[i]) {
                cnt1++;
            } else if (el2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Verify the counts of el1 and el2
        cnt1 = 0, cnt2 = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (el1 == nums[i]) cnt1++;
            if (el2 == nums[i]) cnt2++;
        }

        int threshold = n / 3;
        if (cnt1 > threshold) res.push_back(el1);
        if (cnt2 > threshold) res.push_back(el2);

        sort(res.begin(), res.end()); // Optional: To return elements in sorted order

        return res;
    }
};



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
