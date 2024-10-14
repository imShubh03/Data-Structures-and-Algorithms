#include <bits/stdc++.h>
using namespace std;

/* MEMOIZATION   time: O(n)  space: O(n) + O(n) */
int climbStairs(int n, vector<int> &dp) {
    // Base case
    if (n <= 1) return n;

    // Check if already computed
    if (dp[n] != -1) {
        return dp[n];
    }


    // Calculate and store the result in ways array
    dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);

    return dp[n];
}

/* TABULATION  time: O(n)  space: O(n) */
int climbStairs(int n, vector<int> &ways) {
    ways[0] = 0;
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}

/* SPACE OPTIMIZATION   time: O(n)  space: O(1) */
int climbStairs(int n) {
    if (n <= 1) return n;

    int step1 = 0; // Equivalent to previous two steps
    int step2 = 1; // Equivalent to previous one step

    for (int i = 2; i <= n; i++) {
        int current = step1 + step2; // Current number of ways
        step1 = step2; // Move step2 to step1
        step2 = current; // Update step2 to current
    }

    return step2; // Final result
}

int main() {
    int n;
    cin >> n; // Input the value of n

    vector<int> dp(n + 1, -1);

    int res = climbStairs(n); 
    cout << res << endl;

    return 0;
}
