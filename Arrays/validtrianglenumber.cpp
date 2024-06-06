#include <vector>
#include <algorithm>
using namespace std;
#include<iostream>
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i =0;i<n-2;i++){
            for(int j =i+1;j<n-1;j++){
                for(int k =j+1;k<n;k++){
                    if(nums[i] + nums[j] > nums[k] && nums[j] + nums[k] > nums[i] && nums[i] + nums[k] > nums[j]){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

/*
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());

        int count = 0;

        // Step 2: Fix the third side (largest side) and use two pointers for the other two sides
        for (int k = n - 1; k >= 2; --k) {
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All elements between i and j form valid triangles with nums[k]
                    count += (j - i);
                    --j; // Decrement j using pre-decrement
                } else {
                    ++i; // Increment i using post-increment
                }
            }
        }

        return count;
    }
};
O(n^2)
*/

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {10, 21, 22, 100, 101, 200, 300};
    int result = sol.triangleNumber(arr);
    cout << "Number of triangles: " << result << std::endl;
    return 0;
}
