#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int firstOccurrence(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevent potential overflow

            if (target == nums[mid]) {
                first = mid;
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOccurrence(vector<int>& nums, int target, int n) {
        int low = 0;
        int high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid]) {
                last = mid;
                low = mid + 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurrence(nums, target, n);
        if (first == -1) return {-1, -1};
        int last = lastOccurrence(nums, target, n);

        return {first, last};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> result = solution.searchRange(nums, target);
    cout << "First and last occurrences of " << target << " are at indices: ";
    cout << result[0] << " and " << result[1] << endl;

    return 0;
}
