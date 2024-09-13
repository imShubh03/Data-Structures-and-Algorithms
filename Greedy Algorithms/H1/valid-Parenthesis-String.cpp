#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s, int ind, int cnt) {
        int n = s.size();
        // Base cases
        if (cnt < 0) return false;
        if (ind == n) {
            return cnt == 0;
        }

        // Recursive cases
        if (s[ind] == '(') {
            return isValid(s, ind + 1, cnt + 1);
        } else if (s[ind] == ')') {
            return isValid(s, ind + 1, cnt - 1);
        } else { // s[ind] == '*'
            // Try treating '*' as '(', ')', or ignore it
            return isValid(s, ind + 1, cnt + 1) || isValid(s, ind + 1, cnt - 1) || isValid(s, ind + 1, cnt);
        }
    }

    bool checkValidString(string s) {
        return isValid(s, 0, 0);
    }
};

// Main function to test the implementation
int main() {
    Solution sol;

    string test1 = "(*)";
    string test2 = "(*)(";

    cout << "Test 1: " << (sol.checkValidString(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (sol.checkValidString(test2) ? "Valid" : "Invalid") << endl;

    return 0;
}
