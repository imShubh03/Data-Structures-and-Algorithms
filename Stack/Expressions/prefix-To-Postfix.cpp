#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string &s) {
    int n = s.size();
    stack<string> st;

    // Iterate through the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If the character is an operand, push it to the stack
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        // If the character is an operator, pop two operands,
        // form a postfix expression and push it back to the stack
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            // Form the postfix expression: t1 t2 operator
            string ans = t1 + t2 + s[i];
            st.push(ans);
        }
    }

    // The final element in the stack is the full postfix expression
    return st.top();
}

int main() {
    string prefixExpression = "*-A/BC-/AKL";
    string postfixExpression = prefixToPostfix(prefixExpression);

    cout << "Prefix Expression: " << prefixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}
