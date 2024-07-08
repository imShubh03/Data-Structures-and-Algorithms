#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();

        // Iterate from the last character to the first character
        for (int i = n - 1; i >= 0; i--)
        {
            // Convert the character at num[i] to its integer value and check if it's odd
            if ((num[i] - '0') % 2 != 0)
            {

                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};

int main()
{
    Solution sol;

    string input1 = "52";
    string output1 = sol.largestOddNumber(input1);
    cout << "Input: " << input1 << endl;
    cout << "Output: " << output1 << endl;

    return 0;
}
