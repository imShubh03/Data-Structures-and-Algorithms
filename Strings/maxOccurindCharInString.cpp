#include <iostream>
#include <unordered_map>
#include <cctype>    // for std::tolower
using namespace std;

class Solution {
public:
    char getMaxOccurringChar(string str) {
        unordered_map<char, int> freq;

        // Convert all characters to lowercase
        for (char& ch : str) {
            ch = tolower(ch);
        }

        // Count frequencies of each character
        for (char ch : str) {
            freq[ch]++;
        }

        char maxChar = '\0';
        int maxCount = 0;

        // Find character with maximum frequency, handling ties lexicographically
        for (auto& it : freq) {
            if (it.second > maxCount || (it.second == maxCount && it.first < maxChar)) {
                maxChar = it.first;
                maxCount = it.second;
            }
        }
        
        return maxChar;
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Solution sol;
    char maxChar = sol.getMaxOccurringChar(str);

    if (maxChar != '\0') {
        cout << "The maximum occurring character is '" << maxChar << "'." << endl;
    } else {
        cout << "String is empty." << endl;
    }

    return 0;
}
