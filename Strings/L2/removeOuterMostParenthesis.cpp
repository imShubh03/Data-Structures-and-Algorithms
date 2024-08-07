#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* time: O(N)  space: O(N)
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
*/

// time O(N) , space:O(1) the string ans doesnt contributr to space
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int cnt = 0;
        string ans = "";
        for (char ch : s)
        {
            if (ch == '(')
            {
                if (cnt > 0)
                { // dont want the first '(' in ans
                    ans += ch;
                }
                cnt++;
            }
            else if (ch == ')')
            {
                if (cnt > 1)
                { // dont want the last ')' in ans
                    ans += ch;
                }
                cnt--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string input = "(()())(())";
    string output = sol.removeOuterParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;

    return 0;
}
