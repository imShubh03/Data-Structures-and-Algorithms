#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // Character count for s1
        int count1[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // Traverse s2 in window size of s1
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};

        while (i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // Now check if both count1 and count2 are equal
        if (isEqual(count1, count2)) {
            return true;
        }

        // Move to next window
        while (i < s2.length()) {
            // Add new char
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            // Remove old char
            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            // Check if equal
            if (isEqual(count1, count2)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s1 = "ab";
    string s2 = "eidboaooo";

    if (solution.checkInclusion(s1, s2)) {
        cout << "s1's permutation is a substring of s2" << endl;
    } else {
        cout << "s1's permutation is not a substring of s2" << endl;
    }

    return 0;
}
