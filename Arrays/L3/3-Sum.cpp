#include<bits/stdc++.h>
using namespace std;

/* brute : time ~ O(n^3) * log(no of uniq elem)  space:2 * O(no of unique trip) {set, ans}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
*/

/* better time ~ O(n^2) * log(no of uniq elem)  space: O(n){hashset} +2 * O(no of unique trip) {set, ans}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            set<int> hashset;
            for(int j = i + 1; j < n; j++) {
                int third = -(nums[j] + nums[i]);
                
                // Check if 'third' exists in the hashset
                if(hashset.count(third)) { // Fix: It should check if 'third' exists, not if it doesn't
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                
                // Insert current element nums[j] into hashset
                hashset.insert(nums[j]);
            }
        }

        // Convert set to vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
*/

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    for(auto &vec : result) {
        for(auto &val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
