#include<bits/stdc++.h>
using namespace std;

/* brute : time:O(n^2) space:O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = i; j < n; j++) {
                prod *= nums[j];
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
};
*/

// optimal time:O(n) space:O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - 1 - i];

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
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
    cout << sol.maxProduct(nums) << endl;
    return 0;
}
