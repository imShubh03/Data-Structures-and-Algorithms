#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isValid(string str){
        stack<int>st;
        for(int i =0; i<str.length();i++){
            char ch = str[i];
            //if opening brack then push
            if(ch == '[' || ch == '{' || ch == '('){
                st.push(ch);
            }
            else{
                //definitely closing brack
                //check if no closing brack
                if(st.empty()){
                    return false;
                }
                else{
                    //there are closin brack
                    char top = st.top();
                    if((ch == ')' && top=='(') || (ch == ']' && top==']') || (ch=='}' && top=='{')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};

int main() {
    string str;
    cout<<"enter the strings of bracket"<<endl;
    cin>>str;

    Solution sol;

    if (sol.isValid(str)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}