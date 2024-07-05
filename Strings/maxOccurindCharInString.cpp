#include <iostream>
#include <unordered_map>
using namespace std;


//  time : O(N)  space:O(N)
class Solution {
public:
    char getMaxOccurringChar(string str) {
        if (str.empty()) {
            return '\0';
        }

        unordered_map<char, int> map;

        // Increment the frequency of each character
        for (char ch : str) {
            map[ch]++;
        }

        char maxChar = '\0';
        int maxCount = 0;

        // Find the character with the maximum frequency
        for (auto it : map) {
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
