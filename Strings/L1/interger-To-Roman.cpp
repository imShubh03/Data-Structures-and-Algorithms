#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int n) {
        static vector<int> val = {1000, 900, 500, 400, 100, 90, 50,
                                  40,   10,  9,   5,   4,   1};
        static vector<string> symb = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                      "XL", "X",  "IX", "V",  "IV", "I"};
        string ans = "";

        for (int i = 0; i < 13; i++) {
            if (n == 0)
                break;

            int times = n / val[i];

            while (times--) {
                ans += symb[i];
            }

            n = n % val[i];
        }
        return ans;
    }
};

int main() {
    int num;
    cin>>num;

    Solution sol;
    string ans = sol.intToRoman(num);
    cout<<ans;

    return 0;
}