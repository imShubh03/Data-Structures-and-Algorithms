#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string prefixToInfixConversion(string &s) {
        int i = s.size() - 1;
        stack<string> st;

        while (i >= 0) {
            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') || 
                (s[i] >= '0' && s[i] <= '9')) {
                st.push(string(1, s[i])); // Convert char to string and push
            } 
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string ans = '(' + t1 + s[i] + t2 + ')';
                st.push(ans);
            }
            i--;
        }

        return st.top();
    }
};

int main() {
    Solution sol;

    string prefixExpression = "*-A/BC-/AKL";
    string infixExpression = sol.prefixToInfixConversion(prefixExpression);

    cout << "Prefix Expression: " << prefixExpression << endl;
    cout << "Infix Expression: " << infixExpression << endl;

    return 0;
}
