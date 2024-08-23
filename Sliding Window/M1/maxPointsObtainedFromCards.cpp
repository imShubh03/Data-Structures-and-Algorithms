#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(int arr[], int n, int k) {
        int lsum = 0, rsum = 0;
        int maxSum = 0;

        // Calculate the sum of the first k cards
        for(int i = 0; i <= k-1; i++) {
            lsum += arr[i];
        }
        maxSum = lsum;

        // Now remove the indexes from the front and add from the back
        int rInd = n - 1;
        for(int i = k - 1; i >= 0; i--) {
            lsum = lsum - arr[i];
            rsum = rsum + arr[rInd];
            rInd--;
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};

int main() {
    int k = 4;
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.maxScore(arr, n, k);
    cout << "Max Score: " << result << endl;

    return 0;
}
