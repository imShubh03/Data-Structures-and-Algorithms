#include <bits/stdc++.h>

using namespace std;

/*brute, time:O(n^2) space:O(1)
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
*/

/*
//optimized for (-ve , 0, +ve integers in array), time:O() space:O(1)
class Solution {
public:
    int lenOfLongSubarr(int arr[], int N, int K) {
        map<int,int>preSumMap;
        int sum =0;
        int maxlen=0;
        for(int i =0;i<N;i++){
            sum+=arr[i];
            if(sum==K) {
                maxlen=max(maxlen,i+1);
            }
            int remaining= sum-K;
            if(preSumMap.find(remaining)!=preSumMap.end()){
                int len = i - preSumMap[remaining];
                maxlen=  max(maxlen,len);
            }

            if(preSumMap.find(sum)==preSumMap.end()){
                preSumMap[sum]=i;
            }
        }
        return maxlen;
    }
};
*/


//most optimal for (0 and +ve integers only)  time:O(2n)  space:O(1)
class Solution {
public:
    int lenOfLongSubarr(int arr[], int N, int K){
    int left = 0;
    int right = 0;
    int maxlen = 0;
    int sum = 0;

    while (right < N) {
        sum += arr[right];

        while (sum > K && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == K) {
            maxlen = max(maxlen, right - left + 1);
        }

        right++;
    }
    return maxlen;
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
    cout << "Enter the target (K) : ";
    cin >> K;

    int len = sol.lenOfLongSubarr(arr, n, K);
    cout << "Length of the longest subarray with sum equal to " << K << " is " << len << endl;

    return 0;
}