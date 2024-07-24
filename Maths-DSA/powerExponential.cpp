#include <iostream>
using namespace std;

/*  time:O(n)  space:O(1)
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


//tc: O(log base 2 to n)  space:O(1)  handles negative expon
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Use long long to handle edge cases like n = INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x;
                N -= 1;
            } else {
                x =X*  x;
                N /= 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    double x;
    int n ;
    cout<<"enter base"<<endl;
    cin>>x;
    cout<<"enter exponent"<<endl;
    cin>>n;
    cout << x <<"^" << n << "="<< sol.myPow(x, n) << endl; 

    return 0;
}
