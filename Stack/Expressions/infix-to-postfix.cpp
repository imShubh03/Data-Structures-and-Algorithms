#include <bits/stdc++.h>

using namespace std;

// Class to handle the infix to postfix conversion
class Solution {
public:
    // Function to return the priority of operators
    int priority(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    // Function to convert infix expression to postfix
    string infixToPostfix(string exp) {
        int n = exp.length();
        stack<char> st;
        string ans = "";

        for (int i = 0; i < n; i++) {
            // If character is an operand, add it to the output string
            if ((exp[i] >= 'A' && exp[i] <= 'Z') || 
                (exp[i] >= 'a' && exp[i] <= 'z') || 
                (exp[i] >= '0' && exp[i] <= '9')) {
                ans += exp[i];
            } 
            // If the character is '(', push it to stack
            else if (exp[i] == '(') {
                st.push(exp[i]);
            } 
            // If the character is ')', pop and output from the stack
            // until an '(' is encountered
            else if (exp[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Pop '('
            } 
            // An operator is encountered
            else {
                while (!st.empty() && priority(exp[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }

        // Pop all the operators from the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string infixExpression = "(A+B)*(C-D)";
    string postfixExpression = sol.infixToPostfix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}
