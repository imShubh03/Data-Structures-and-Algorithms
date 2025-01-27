#include <bits/stdc++.h>
using namespace std;

//brute: time:O(n^2) space:O(1)
int getLengthofLongestSubstring(int k, string s){
    // Write your code here.
    int n = s.length();
    int maxlen = 0;
    for (int i = 0; i < n; i++){
        map<char, int> mp;
        for (int j = i; j < n; j++){
            mp[s[j]]++;

            if (mp.size() <= k){
                maxlen = max(maxlen, j - i + 1);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}

// optimised:O(2n)
int getLengthofLongestSubstring(int k, string s){
    int n = s.length();
    if (n == 0 || k == 0) return 0;

    int maxlen = 0;
    int left = 0;
    map<char, int> mp;

    for (int right = 0; right < n; ++right){
        mp[s[right]]++;

        while (mp.size() > k){
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
}

int main()
{
    string s = "eceba";
    int k = 2;
    cout << getLengthofLongestSubstring(k, s) << endl; // Output should be 3
    return 0;
}
