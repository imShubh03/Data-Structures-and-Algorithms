#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lenOfLongSubarr(int arr[], int N, int K) {
        int len = 0;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += arr[j];
                if (sum == K) {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int K;
    cout << "Enter the target sum: ";
    cin >> K;

    int len = sol.lenOfLongSubarr(arr, n, K);
    cout << "Length of the longest subarray with sum equal to " << K << ": " << len << endl;

    return 0;
}