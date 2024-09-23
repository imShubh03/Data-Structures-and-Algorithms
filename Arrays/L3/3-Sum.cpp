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

//optimal time ~ O(n^2) + O(n logn)  space: O(1) {ans to return so ignored}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for(int i =0; i<n; i++){
            // if is are same then move
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // if j and k are equal to prev then
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

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
