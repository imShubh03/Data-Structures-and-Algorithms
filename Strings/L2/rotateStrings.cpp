#include <bits/stdc++.h>
using namespace std;

/*TC: O(n^2) SC"O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        if(m != n) return false;
        for(int cnt =1; cnt <=m; cnt++){
            rotate(s.begin(), s.begin()+1, s.end());
            if( s == goal) return true;
        }

        return false;
    }
};
*/

/*   //return no of rotations
int rotateString(string s, string goal)
{
    // If lengths are not equal, return -1 (indicating it's not possible)
    if (s.length() != goal.length())
    {
        return -1;
    }

    queue<char> q1, q2;
    // Push the characters of `s` into `q1`
    for (int i = 0; i < s.length(); i++)
    {
        q1.push(s[i]);
    }
    // Push the characters of `goal` into `q2`
    for (int i = 0; i < goal.length(); i++)
    {
        q2.push(goal[i]);
    }

    // Try all rotations of `goal`
    int k = goal.size();
    int operations = 0;
    while (k != 0)
    {
        // Check if `q1` and `q2` are equal
        if (q1 == q2)
        {
            return operations;
        }

        // Rotate `q2`
        char ch = q2.front();
        q2.pop();
        q2.push(ch);

        operations++;
        k--;
    }

    // If no rotation matches, return -1
    return -1;
}
*/


/* return true/false   time:O(n)  space:O(n)
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // if length not equal then never true
        if (s.length() != goal.length())
        {
            return false;
        }

        queue<char> q1, q2;
        // push the s in q1
        for (int i = 0; i < s.length(); i++)
        {
            q1.push(s[i]);
        }
        // push the goal in q2
        for (int i = 0; i < goal.length(); i++)
        {
            q2.push(goal[i]);
        }
        // ini k = goal.size() and not goal.size()-1 becoz it both equal that case
        int k = goal.size();
        while (k != 0)
        {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);

            if (q1 == q2)
            {
                return true;
            }
            k--;
        }
        return false;
    }
};
*/


class Solution{
    public:
    bool rotateString(string s, string goal){
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};

int main()
{
    string s, goal;

    cout << "enter both string" << endl;
    cin >> s;
    cin >> goal;

    Solution sol;
    bool ans = sol.rotateString(s, goal);

    cout << "answer is " << ans;

    return 0;
}