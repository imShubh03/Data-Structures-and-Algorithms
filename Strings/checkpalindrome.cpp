#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*  O(n) space
    bool isPalindrome(vector<char> &str) {
        int n = str.size();
        vector<char> rev;

        // Create the reversed string
        for (int i = n - 1; i >= 0; i--) {
            rev.push_back(str[i]);
        }

        // Compare the original string with the reversed string
        for (int i = 0; i < n; i++) {
            if (str[i] != rev[i]) {
                return false;
            }
        }
        return true;
    }
    */


    bool isPalindrome(vector<char> &str){
        int n = str.size();
        int low =0;
        int high = n-1;

        while(low<=high){
            if(str[low] == str[high]){
                return true;
            }
            else{
                return false;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<char> str(n);
    cout << "Enter the string: ";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    Solution solution;
    if (solution.isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
