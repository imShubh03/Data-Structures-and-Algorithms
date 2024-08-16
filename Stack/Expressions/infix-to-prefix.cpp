#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    // Function to return the priority of operators
    int priority(char c){
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    // Convert infix to postfix
    string infixToPostfix(string exp){
        stack<char> st;
        string ans = "";
        int n = exp.size();

        // Loop through each character in the expression
        for (int i = 0; i < n; i++){
            // If it's an operand, add it to the result
            if ((exp[i] >= 'A' && exp[i] <= 'Z') ||
                (exp[i] >= 'a' && exp[i] <= 'z') || 
                (exp[i] >= '0' && exp[i] <= '9')){
                ans += exp[i];
            }
            // If it's an '(', push to stack
            else if (exp[i] == '('){
                st.push(exp[i]);
            }
            // If it's a ')', pop and add to result until '(' is found
            else if (exp[i] == ')'){
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // pop '('
            }
            // If it's an operator
            else{
                // Corrected the logic to compare the precedence and push the operator into the stack
                while (!st.empty() && priority(exp[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }

        // Pop all the operators left in the stack
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans; // Removed unnecessary reversal as it's not needed in postfix conversion
    }

    // Function to convert infix expression to prefix
    string infixToPrefix(string exp){
        /*
        Reverse the given infix expression
        Replace '(' with ')' and vice versa
        Convert the reversed infix to postfix
        Reverse the postfix to get the prefix
        */

        reverse(exp.begin(), exp.end()); // Step 1: Reverse the infix expression
        int l = exp.size();

        for (int i = 0; i < l; i++){
            // Swap '(' with ')' and vice versa
            if (exp[i] == '(')
            {
                exp[i] = ')';
            }
            else if (exp[i] == ')')
            {
                exp[i] = '(';
            }
        }

        string postfix = infixToPostfix(exp); // Step 3: Convert to postfix
        reverse(postfix.begin(), postfix.end()); // Step 4: Reverse to get the prefix
        return postfix;
    }
};

int main(){
    Solution sol;

    string infixExpression = "(A+B)*(C-D)";
    string prefixExpression = sol.infixToPrefix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
