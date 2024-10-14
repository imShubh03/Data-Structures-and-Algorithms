#include <bits/stdc++.h>
using namespace std;

/* MEMOISATION   time:O(n)  space:O(n) + O(n)
int fibonacci(int n, vector<int> &dp) {
    // base case
    if (n <= 1) return n;
    // check if already computed
    if (dp[n] != -1) {
        return dp[n];
    }

    // calculate and store
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);

    return dp[n];
}
*/

/* TABULAION  time:O(n) space:O(n)
int fibonacci(int n, vector<int>&dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i =2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i -2];
    }

    return dp[n];
}
*/

// SPACE OPTIMISATION   time:O(n) space:O(1)
int fibonacci(int n){
    if(n <=1 ) return n;

    int prev2 =0;
    int prev1 = 1;

    for(int i =2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    // int res = fibonacci(n, dp);
    int res = fibonacci(n);
    cout << res << endl;

    return 0;
}
