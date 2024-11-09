#include <bits/stdc++.h>
using namespace std;

/* recursion
int climbStairs(int n){
    //base case
    if(n<=1) return 1;

    return climbStairs(n-1) + climbStairs(n-2);
}
*/

/* MEMOIZATION   time: O(n)  space: O(n) + O(n) */
int climbStairs(int n, vector<int> &dp) {
    // Base case: for n = 0 or n = 1, there is 1 way
    if (n <= 1) return 1;

    // Check if already computed
    if (dp[n] != -1) {
        return dp[n];
    }

    // Calculate and store the result in dp array
    dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);

    return dp[n];
}
*/


/* TABULATION  time: O(n)  space: O(n) */
int climbStairs(int n, vector<int> &ways) {
    // Base case initialization: 1 way for 0 or 1 steps
    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}
*/

// SPACE OPTIMIZATION   time: O(n)  space: O(1) 
int climbStairs(int n) {
    // Base case: 1 way for 0 or 1 steps
    if (n <= 1) return 1;

    int step1 = 1; // Equivalent to the number of ways for n = 0
    int step2 = 1; // Equivalent to the number of ways for n = 1

    for (int i = 2; i <= n; i++) {
        int current = step1 + step2; // Current number of ways
        step1 = step2; // Move step2 to step1
        step2 = current; // Update step2 to current
    }

    return step1; // Final result
}

int main() {
    int n;
    cin >> n; // Input the value of n

    vector<int> dp(n + 1, -1);

    int res = climbStairs(n); 

    cout << res << endl;

    return 0;
}
