#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* TC O(N)
class solution{
    public:
    int gcd(int a, int b) {
        for (int i = min(a, b); i >= 1; i--) {
            if (a % i == 0 && b % i == 0) {
            return i;
            break;
            }
        }
    return 1; 
};
*/

class solution{
    public:
    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b) a= a%b;
            else b = b%a;
        }
        if(a==0) return b;
        return a;
    }
};

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    solution sol;
    int result = sol.gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
