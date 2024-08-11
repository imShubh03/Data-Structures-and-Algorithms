#include <iostream>
using namespace std;

/*  brute : works for positive n only  time:O(n) space:O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        for (int i = 0; i < n; ++i) {
            ans *= x;
        }
        return ans;
    }
};
*/


//better time:O(logn) space:O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;  // Store n in a long long variable to handle negative values and avoid overflow

        // If n is negative, make nn positive
        if (nn < 0) nn = -nn;

        while (nn) {
            if (nn % 2 == 0) {
                x = x * x;  // Square the base
                nn = nn / 2;  // Halve the exponent
            } else {
                ans = ans * x;  // Multiply the current base with ans
                nn = nn - 1;  // Decrement the exponent by 1
            }
        }

        // If the original n was negative, take the reciprocal of the answer
        if (n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }
};


int main() {
    Solution sol;
    double x;
    int n;
    
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;
    
    double result = sol.myPow(x, n);
    cout << x << " raised to the power of " << n << " is: " << result << endl;
    
    return 0;
}
