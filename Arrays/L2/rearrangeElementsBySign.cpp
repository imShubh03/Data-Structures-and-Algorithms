#include <iostream>
#include <vector>

using namespace std;

/*  brute, time: O(2n) , space:O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> posArr;
        vector<int> negArr;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                posArr.push_back(nums[i]);
            } else {
                negArr.push_back(nums[i]);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            nums[2 * i] = posArr[i];
            nums[2 * i + 1] = negArr[i];
        }

        return nums;
    }
};
*/

/*optimised one  time: O(n)  space:(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int posIndex =0;
        int negIndex = 1;
        for(int i =0;i<n;i++){
            if(nums[i]<0){
                ans[negIndex]= nums[i];
                negIndex+=2;
            }
            else{
                ans[posIndex]= nums[i];
                posIndex+=2;
            }
        }
        return ans;
    }
};
*/

//type 2 of que where no Of +ves != no of -ves

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;

        // Separate the numbers into positive and negative vectors
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        // Merge the two vectors back into nums in alternating order
        if (pos.size() > neg.size()) {
            for (int i = 0; i < neg.size(); i++) {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++) {
                nums[index++] = pos[i];
            }
        } else {
            for (int i = 0; i < pos.size(); i++) {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++) {
                nums[index++] = neg[i];
            }
        }

        return nums;
    }
};




int main() {
    Solution solution;
    vector<int> nums = {3, 1, -2, -5, 2, -4, 1, 8};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> rearranged = solution.rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
