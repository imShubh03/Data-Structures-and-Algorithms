#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;  // index to store the result in the original array
        int n = chars.size();

        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // Store the current character
            chars[ansIndex] = chars[i];
            ansIndex++;

            // Store the count if it is more than 1
            int count = j - i;
            if (count > 1) {
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansIndex] = ch;
                    ansIndex++;
                }
            }

            // Move to the next new character
            i = j;
        }
        return ansIndex;
    }
};

int main() {
    Solution sol;

    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength1 = sol.compress(chars1);
    cout << "Compressed characters (length " << newLength1 << "): ";
    for (int i = 0; i < newLength1; ++i) {
        cout << chars1[i];
    }
    cout << endl;

    return 0;
}
