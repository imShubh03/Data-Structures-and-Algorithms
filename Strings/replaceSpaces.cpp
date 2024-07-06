#include <bits/stdc++.h>

using namespace std;

/*     TC: O(N)  SC:O(N)
class Solution {
    public:
    string replaceSpaces(string &str){
        string temp ="";

        for(int i=0; i<str.length();i++){
            if(str[i]==' '){
                temp.push_back('@');
                temp.push_back('4');
                temp.push_back('0');
            }
            else{
                temp.push_back(str[i]);
            }
        }
        return temp;
    }
};
*/


//TC:O(N)   SC:O(1)
class Solution {
public:
    void replaceSpaces(string &str) {
        int spaceCount = 0;
        int originalLength = str.length();
        
        // Count spaces
        for (int i = 0; i < originalLength; i++) {
            if (str[i] == ' ') {
                spaceCount++;
            }
        }

        // Calculate new length of the string
        int newLength = originalLength + spaceCount * 2;
        str.resize(newLength); // Resize the string to the new length

        // Replace spaces from the end
        int j = newLength - 1;
        for (int i = originalLength - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[j] = '0';
                str[j - 1] = '4';
                str[j - 2] = '@';
                j -= 3;
            } else {
                str[j] = str[i];
                j--;
            }
        }
    }
};
int main() {

    string str;
    cout<<"enter the string"<<endl;
    getline(cin,str);

    Solution sol;
    cout<<"ans is "<<sol.replaceSpaces(str)<<endl;


    return 0;
}