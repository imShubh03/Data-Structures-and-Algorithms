#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToInfix(string postfix) {
        int i = 0;
        stack<string> st;

        while (i < postfix.size()) {
            // If character is an operand, push it to the stack
            if ((postfix[i] >= 'A' && postfix[i] <= 'Z') ||
                (postfix[i] >= 'a' && postfix[i] <= 'z') || 
                (postfix[i] >= '0' && postfix[i] <= '9')) {
                st.push(string(1, postfix[i])); // Convert char to string and push
            }
            // If character is an operator, pop two elements from stack,
            // form an infix expression, and push the result back to the stack
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string ans = '(' + t2 + postfix[i] + t1 + ')';
                st.push(ans);
            }
            i++;
        }

        // The final element in the stack is the full infix expression
        return st.top();
    }
};

int main() {
    Solution sol;

    string postfixExpression = "AB+C*D-";
    string infixExpression = sol.postToInfix(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Infix Expression: " << infixExpression << endl;

    return 0;
}
