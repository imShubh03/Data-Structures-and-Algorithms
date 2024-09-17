#include<bits/stdc++.h>
using namespace std;

/* brute : time:O(n^2) space:O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            int currSum = 0;
            for(int j = i; j < n; j++) {
                currSum += nums[j];
                if (currSum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
*/

// oprtimal 2 pointers
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left=0, right = 0;
        int sum =0, maxlen =0;
        while(right < n){
            sum += nums[right];
            while(sum > k && left<=right){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                maxlen = max(maxlen, right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int k;
    cin >> k;
    
    Solution sol;
    int ans = sol.subarraySum(nums, k);
    cout<<ans<<endl;
    
    return 0;
}
