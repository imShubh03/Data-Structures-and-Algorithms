#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Function to find all subset sums
    void findSum(vector<int> arr, int n, int index, int sum, vector<int>& subsetSum) {
        // Base case: if we reach the end of the array
        if(index == n) {
            subsetSum.push_back(sum);
            return;
        }
        
        // Pick the current element
        findSum(arr, n, index + 1, sum + arr[index], subsetSum);
        
        // Do not pick the current element
        findSum(arr, n, index + 1, sum, subsetSum);
    }

    // Function to get all subset sums
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> subsetSum;
        findSum(arr, n, 0, 0, subsetSum);
        sort(subsetSum.begin(), subsetSum.end());
        return subsetSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    vector<int> result = sol.subsetSums(arr, n);

    // Print the result
    cout << "Subset sums are: ";
    for(int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
