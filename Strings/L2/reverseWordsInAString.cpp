#include <bits/stdc++.h>

using namespace std;

/*  time: O(N) , space: O(N)
class Solution {
public:
    string reverseWords(string str) {
        int i = str.length() - 1;
        string ans = "";
        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && str[i] == ' ') {
                i--;
            }

            if (i < 0) break;

            int j = i;

            // Skip non-spaces (i.e., characters of a word)
            while (i >= 0 && str[i] != ' ') {
                i--;
            }

            if (!ans.empty()) {
                ans += " ";
            }
            ans += str.substr(i + 1, j - i);
        }
        return ans;
    }
};
*/

/*  time: O(N) , space: O(N)
class Solution {
public:
    string reverseString(string &str) {
        int n = str.size();
        stringstream ss(str);
        string token = "";
        string ans = "";

        // Split the string into words and construct the reversed result
        while (ss >> token) {
            // If 'ans' is not empty, prepend 'token' with a space
            if (!ans.empty()) {
                ans = token + " " + ans;
            } 
            // Otherwise, directly assign 'token' to 'ans'
            else {
                ans = token;
            }
        }

        return ans;
    }
};
*/


// time: O(N) and space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        // first reverse the entire
        reverse(s.begin(), s.end());

        int i = 0;
        int l = 0;
        int r = 0;

        while(i<n){
            while(i<n && s[i] != ' '){
                s[r]=s[i];
                i++;
                r++;
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l=r;
            }
            i++;
        }
        s=s.substr(0,r-1);
        return s;
    }
};

int main() {
    string s = " the sky is blue ";

    Solution sol;

    cout << "the output: " << sol.reverseWords(s) << endl;

    return 0;
}
