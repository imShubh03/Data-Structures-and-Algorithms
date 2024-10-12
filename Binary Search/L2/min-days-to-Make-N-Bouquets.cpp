#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int day, int m, int k, int n) {
    int cnt = 0;
    int noofBq = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        } else {
            noofBq += (cnt / k);
            cnt = 0;
        }
    }
    noofBq += (cnt / k);
    return noofBq >= m;
}
int minDays(vector<int>& arr, int m, int k) {
    int n = arr.size();
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    
    for (int i = mini; i <= maxi; i++) {
        if (isPossible(arr, i, m, k, n)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m, k;
    cin >> m >> k;

    int ans = minDays(arr, m, k);
    cout << ans;

    return 0;
}
