#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    bool isIsomorphic(string s, string t){
        int n = s.length();

        unordered_map<char,char>map1,map2;

        for(int i =0;i<n;i++){
            char ch1= s[i];
            char ch2 = t[i];

            if((map1.find(ch1)!=map1.end() && map1[ch1]!=ch2) ||
            (map2.find(ch2)!=map2.end() && map2[ch2]!=ch1 )){
                return false;
            }

            map1[ch1]=ch2;
            map2[ch2]=ch1;
        }

        return true;
    }
};

/*
//TC : O(n) SC:O(256)ie all ascii char
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        char map1[256] = {0};
        char map2[256] = {0};

        // Length of the strings (both are assumed to be of the same length)
        int n = s.length();

        // Iterate through each character in the strings
        for (int i = 0; i < n; i++)
        {
            char ch1 = s[i]; // Current character from string s
            char ch2 = t[i]; // Current character from string t

            // Check if there is an existing mapping from s to t and if it is consistent
            if ((map1[ch1] != 0 && map1[ch1] != ch2) ||
                (map2[ch2] != 0 && map2[ch2] != ch1))
            {
                return false; // If inconsistent mapping is found, return false
            }

            // Establish mapping from s to t and t to s
            map1[ch1] = ch2;
            map2[ch2] = ch1;
        }

        return true; // If no inconsistencies are found, return true
    }
};
*/

int main(){

    Solution sol;
    // string s="badc";
    // string t ="baba";

    string s="egg";
    string t ="add";

    bool ans = sol.isIsomorphic(s,t);

     cout << (ans ? "Isomorphic" : "Not Isomorphic") << endl; // Print the result

    return 0;
}