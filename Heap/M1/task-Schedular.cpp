#include <bits/stdc++.h>
using namespace std;

/* USING HEAP
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mp;
        
        for(char &ch : tasks) {
            mp[ch]++;
        }

        priority_queue<int> pq; //max heap
        //we want to finish the process which is most occurring (having highest frequency)
        //so that we don't have to finish in the last with p gaps.
        int time = 0;
        
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i<=n+1; i++) {
                //filling first p+1 characters
                if(!pq.empty()) {
                    temp.push_back(pq.top()-1); //finishing one instance of each process
                    pq.pop();
                }
            }
            
            for(int &freq : temp) {
                if(freq > 0)
                    pq.push(freq);
            }
            
            if(pq.empty()) //all processes finished
                time += temp.size();
            else
                time += (n+1); //we finished p+1 tasks above in the loop
            
        }
        
        return time;
    }
};
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26, 0);

        for(char &ch : tasks){
            mp[ch - 'A']++;
        }

        sort(mp.begin(), mp.end());

        int maxFreq = mp[25];
        int bumps = maxFreq - 1;
        int idleSlots = bumps * n;

        for(int i = 24; i>=0; i--){
            idleSlots = idleSlots - min(mp[i], bumps);
        }

        if(idleSlots > 0){
            return tasks.size() + idleSlots;
        }

        return tasks.size();

    }
};

int main() {
    
    int n;
    cin>>n;

    vector<int>tasks(n);

    for(int i =0; i<n; i++){
        cin>>tasks[i];
    }

    Solution sol;

    int ans = sol.leastInterval(tasks, n);
    cout<<ans;

    return 0;
}