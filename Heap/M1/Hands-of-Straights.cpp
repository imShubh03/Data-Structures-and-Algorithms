#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }

        map<int, int>mp;

        for(int &num: hand){
            mp[num]++;
        }

        while(!mp.empty()){
            //elem mp.begin()->first  freq => mp.begin()->second
            int curr = mp.begin() -> first;

            for(int i =0; i<groupSize; i++){
                if(mp[curr + i] == 0){
                    return false;
                }

                mp[curr + i]--;
                if(mp[curr+i] == 0){
                    mp.erase(curr+i);
                }
            }

        }

        return true;
    }
};

int main() {
    
    int n, groupSize;
    cin>> n, groupSize;

    vector<int>hand(n);

    for(int i =0; i<n; i++){
        cin>>hand[i];
    }

    Solution sol;
    if(sol.isNStraightHand(hand, groupSize)){
        cout<< "possible"<<endl;
    }
    else{
        cout<<"not possible";
    }


    return 0;
}