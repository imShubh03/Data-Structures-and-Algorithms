#include<bits/stdc++.h>
using namespace std;

/* brute : time:O(n^2) space:O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    prod *= nums[j];
                }
            }
            ans[i] = prod;
        }
        return ans;
    }
};
*/


/* better : time:O(3*n) space:O(2n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        vector<int>prefix(n, 1);
        vector<int>suffix(n, 1);

        // calc prefix
        prefix[0] = 1;
        for(int i =1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // calc suffix
        suffix[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i =0; i<n; i++){
            ans[i] = suffix[i] * prefix[i];
        }

        return ans;

    }
};
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);
    
    // Output the result
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
