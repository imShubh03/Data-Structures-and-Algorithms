#include <bits/stdc++.h>

using namespace std;
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

int main() {

    string str;
    cout<<"enter the string"<<endl;
    getline(cin,str);

    Solution sol;
    cout<<"ans is "<<sol.replaceSpaces(str)<<endl;


    return 0;
}