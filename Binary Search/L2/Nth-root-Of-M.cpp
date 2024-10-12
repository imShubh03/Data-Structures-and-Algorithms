#include <bits/stdc++.h>
using namespace std;

/* time: O(m * logn) space: O(1)
int find(int i, int n) {
    long long ans = 1;
    for(int j = 1; j <= n; j++) {
        ans = ans * i;
        if(ans > LLONG_MAX) return ans;  // Compare against m, not LLONG_MAX
    }
    return ans;
}
int Nthroot(int n, int m) {
    for(int i = 1; i <= m; i++) {  
        long long power = find(i, n);  
        if(power == m) {
            return i;
        } else if(power > m) {
            break;
        }
    }
    return -1;
}
*/


// optimised time:O(log m) space:O(1)
// return 0 if mid^n == m
// return 1 if mid^n < m
// return 2 if mid^n > m
int fun(int mid, int n, int m) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= mid;
        if(ans > m) return 2;  // If ans exceeds m, return 2
    }
    if(ans == m) return 0;     // If ans equals m, return 0
    return 1;                  // If ans is less than m, return 1
}

int NthRoot(int n, int m) {
    int l = 1;
    int h = m;
    while(l <= h) {
        int mid = (l + h) / 2;
        int midN = fun(mid, n, m);

        if(midN == 0) return mid;  // If mid^n == m, mid is the root
        else if(midN == 1) l = mid + 1;  // If mid^n < m, search the higher half
        else h = mid - 1;  // If mid^n > m, search the lower half
    }
    return -1;  // If no root is found
}


int main() {
    int n, m;
    cin >> n >> m;

    int ans = Nthroot(n, m);
    cout << ans;

    return 0;
}
