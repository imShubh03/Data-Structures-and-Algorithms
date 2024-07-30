#include<bits/stdc++.h>
using namespace std;

/*  brute : time:O(n) space:O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        
        // Populate the hashmap with counts of each number
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Find the number with exactly one occurrence
        for (auto it : countMap) {
            if (it.second == 1) {
                return it.first;
            }
        }
        
        // Handle edge case if no single non-duplicate element is found
        return -1;
    }
};
*/

/* better: time:O(n) space:O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(nums[i] != nums[i+1]) return nums[i];
            }
            else if(i == n-1){
                if(nums[i] != nums[i-1]) return nums[i];
            }
            else{
                if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
            }
        }
        return -1;
    }
};
*/


// optimised : time:O(logn) space:O(1)
class Solution{
    public:
    int singleNonDuplicate(vector<int>& nums){
        //handle few edge cases
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }

            //eliminate half 
            //we r on left half and ele is on right half
            if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2==1 && nums[mid]!=nums[mid-1])){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8}; 

    int result = solution.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}
