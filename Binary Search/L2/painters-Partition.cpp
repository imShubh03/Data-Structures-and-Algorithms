// same as book allocation/ split arr largest sum

#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int>& boards, int maxTime) {
    int painterCount = 1;
    int timeSpent = 0;

    for (int length : boards) {
        if (timeSpent + length > maxTime) {
            painterCount++;
            timeSpent = length;
        } else {
            timeSpent += length;
        }
    }
    return painterCount;
}
int findMinimumTime(vector<int>& boards, int k) {
    int n = boards.size();
    if (k > n) return -1;

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int minimumTime = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int neededPainters = countPainters(boards, mid);

        if (neededPainters > k) {
            low = mid + 1;
        } else {
            minimumTime = mid;
            high = mid - 1;
        }
    }
    return minimumTime;
}


int main() {
    int n;
    cin>>n;
    vector<int> boards(n);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int result = findMinimumTime(boards, k);
    cout<<result<<endl;

    return 0;
}
