#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans;
        for (auto it : s)
        {
            if (!ans.empty() && it == ans.back())
            {
                ans.pop_back(); // Remove the last character if it matches the current character
            }
            else
            {
                ans.push_back(it); // Add the current character to the result string
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string input;

    // Example test cases
    input = "abbaca";
    cout << "Input: " << input << " | Output: " << sol.removeDuplicates(input) << endl;

    return 0;
}
