#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // Helper function to generate combinations
    void solve(string digits, vector<string>& ans, string op, int index, string map[]) {
        // Base case: if we have processed all digits
        if (index >= digits.length()) {
            ans.push_back(op);  // Store the generated combination
            return;
        }

        int num = digits[index] - '0';  // Convert current digit to an integer
        string val = map[num];  // Get the corresponding string of characters from the map

        // Loop through each character in the corresponding string
        for (int i = 0; i < val.size(); i++) {  // Corrected condition to i < val.size()
            op.push_back(val[i]);  // Add current character to the output string
            solve(digits, ans, op, index + 1, map);  // Recursively generate combinations for the next digit
            op.pop_back();  // Backtrack: remove the last character to try the next one
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;  // Changed to vector<string> to store string combinations
        if (digits.length() == 0) return ans;  // Edge case: if input is empty, return empty result

        string op = "";  // Initialize an empty string to store current combination
        int index = 0;  // Start with the first digit
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  // Digit-to-letter mapping
        
        solve(digits, ans, op, index, map);  // Call the helper function to start generating combinations
        
        return ans;  // Return the list of all generated combinations
    }
};

int main() {
    Solution sol;
    string digits;
    cout << "Enter the digits: ";
    cin >> digits;

    vector<string> combinations = sol.letterCombinations(digits);

    cout << "Possible letter combinations are:" << endl;
    for ( auto combo : combinations) {
        cout << combo << endl;
    }

    return 0;
}
