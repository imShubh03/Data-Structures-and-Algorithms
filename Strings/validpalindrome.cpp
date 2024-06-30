#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) {
            return true;
        } else {
            return false;
        }
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9')) {
            return ch;
        } else {
            return ch - 'A' + 'a';
        }
    }

    bool checkPalindrome(string s) {
        int st = 0;
        int en = s.size() - 1;

        while (st <= en) {
            if (s[st] != s[en]) {
                return false;
            }
            st++;
            en--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string temp = "";

        // Check if character is valid and build temp string
        for (int i = 0; i < s.length(); i++) {
            if (isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }

        // Convert temp string to lowercase
        for (int i = 0; i < temp.length(); i++) {
            temp[i] = toLowerCase(temp[i]);
        }

        return checkPalindrome(temp);
    }
};

int main() {
    Solution sol;
    string input = "A man, A plan, A canal, Panama";

    if (sol.isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
