#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string &s) {
    int i = 0;
    stack<string> st;

    while (i < s.size()) {
        // If character is an operand, push it to the stack
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        // If character is an operator, pop two operands, 
        // form a prefix expression and push it back to the stack
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            // Corrected the order to form prefix expression
            string ans = s[i] + t2 + t1;
            st.push(ans);
        }
        i++;
    }

    // The final element in the stack is the full prefix expression
    return st.top();
}

int main() {
    string postfixExpression = "ABC/-AK/L-*";
    string prefixExpression = postfixToPrefix(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
