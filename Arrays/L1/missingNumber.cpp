#include <bits/stdc++.h>

using namespace std;

/*  brute force, time:O(n^2)  space:O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        for (int i = 0; i <= n; i++) {
            flag = 0;  // Reset flag for each number
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return i;
            }
        }
        return -1;
    }
};
*/


/*  better time:O(n)  space:O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int freqarr[n+1]={0};
        for (int i = 0; i < n; i++) {
            freqarr[nums[i]]++;
        }
        for(int i =0;i<=n;i++){
            if(freqarr[i] == 0){
                return i;
                break;
            }  
        }
        return -1;
    }
};
*/

//optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n*(n+1)/2;
        int actualSum= 0;
        for(int i =0;i<n;i++){
            actualSum+=nums[i];
        }

        return expectedSum-actualSum;
    }
};


int main() {
    Solution solution;

    int n;
    cout << "Enter size of the array: " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find the missing number
    int result = solution.missingNumber(nums);

    // Output the missing number
    cout << "The missing number is: " << result << endl;

    return 0;
}
