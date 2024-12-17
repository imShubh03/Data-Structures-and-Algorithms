#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size(); 
        // Map to store the frequency of each element in the current window
        map<int, int> mp; 
        // Two pointers, i for the start and j for the end of the window
        int i = 0, j = 0; 
        // Variable to store the count of valid subarrays
        long long count = 0; 

        // Traverse the array using the end pointer (j)
        while (j < n) {
            // Increment the frequency of the current element (nums[j])
            mp[nums[j]]++; 
            
            // Shrink the window from the left (move i) if the difference between 
            // the max and min elements > 2
            while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {
                // Decrease the frequency of the element at the start of the window
                mp[nums[i]] -= 1; 
                // Remove the element from the map if its frequency becomes 0
                if (mp[nums[i]] == 0) { 
                    mp.erase(nums[i]); 
                }
                // Move the start pointer of the window
                i++; 
            }

            // Add the number of valid subarrays ending at j
            count += j - i + 1; 
            // Move the end pointer of the window to the right
            j++; 
        }
        
        // Return the total count of valid subarrays
        return count; 
    }
};


int main() {
    // Input size of the array
    int n;
    cin >> n;
    
    // Input the elements of the array
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    // Call the function and output the result
    cout << solution.continuousSubarrays(nums) << endl;

    return 0;
}
