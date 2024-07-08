#include <iostream>
#include <string>
#include<stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for (auto ch : s) {
            if (ch == '(') {
                if (st.size() > 0) {
                    ans.push_back(ch);
                }
                st.push(ch);
            } else if (ch == ')') {
                if (st.size() > 1) {
                    ans.push_back(ch);
                }
                st.pop();
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "(()())(())";
    string output = sol.removeOuterParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;

    return 0;
}
