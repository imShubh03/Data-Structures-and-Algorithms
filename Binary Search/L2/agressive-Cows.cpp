#include<bits/stdc++.h>
using namespace std;

/* time:O(nlogn) + [O(max - min) * O(n)]  space:O(1)
bool func(vector<int>& arr, int ds, int k) {
    int cntcows = 1;
    int lastcow = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - lastcow >= ds) {
            cntcows++;
            lastcow = arr[i];
        }
    }
    if (cntcows >= k) return true;
    return false;
}
int aggressiveCows(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int mini = *min_element(arr.begin(), arr.end());
    int range = maxi - mini;

    for (int i = 0; i <= range; i++) {
        bool canPlace = func(arr, i, k);
        if (!canPlace) {
            return i - 1;
        }
    }
    return range;
}
*/


// time:O(nlogn) + [O(log(max - min)) * O(n)]  space:O(1)
bool func(vector<int>& arr, int ds, int k) {
    int cntcows = 1;
    int lastcow = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - lastcow >= ds) {
            cntcows++;
            lastcow = arr[i];
        }
    }
    if (cntcows >= k) return true;
    return false;
}
int aggressiveCows(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[n-1] + arr[0];
    int ans  = -1;
    while(low <= high){
        int mid = (low+high)/2;
        int canplace= func(arr, mid, k);
        
        if(canplace){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}


int main() {
    int n, k;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> k;
    
    int result = aggressiveCows(arr, k);
    cout << result << endl;
    
    return 0;
}
