#include <iostream>
#include <vector>

using namespace std;

/*
// RECURSIVE
class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (target > nums[mid]) {
            return binarySearch(nums, mid + 1, high, target);
        }
        return binarySearch(nums, low, mid - 1, target);
    }
};
*/

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high){
            int mid = (low+high)/2;

            if(target ==  nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
};



int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;
    int low = 0;
    int high = nums.size() - 1;
    Solution obj;
    int result = obj.binarySearch(nums, low, high, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    return 0;
}
