#include <iostream>
#include <vector>
using namespace std;

//brute : using recursion

//optimal: bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int ssets = 1 << n;
        vector<vector<int>> ans;
        for(int num = 0; num <= ssets - 1; num++) {
            vector<int> temp;
            for(int i = 0; i <= n - 1; i++) {
                if(num & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, element;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        nums.push_back(element);
    }

    vector<vector<int>> subsets = sol.subsets(nums);

    cout << "All possible subsets are:" << endl;
    for ( auto subset : subsets) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
