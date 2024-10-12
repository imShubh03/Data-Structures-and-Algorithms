#include <bits/stdc++.h>
using namespace std;

/* Time : O(n) space: O(1)
int sqrtOfNumber(int x){
    int ans = 1;
    for(int i = 1; i<x; i++){
        if(i * i <= x){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}
*/

/*
// time:O(logn ) space:O(1)
int sqrtOfNumber(int x){
    if(x == 0) return 0;

    int low =0;
    int high = x;
    int ans = 1;

    while(low <= high){
        long long mid = (low + high)/2;

        if(mid * mid <= x){
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}
*/


// most optimised time:O(1) space:O(1)
int sqrtOfNumber(int x){
    long long ans = sqrt(x);
    return ans;
}

int main() {
    int x;
    cin>>x;

    int ans = sqrtOfNumber(x);
    cout<<ans<<endl;

    return 0;
}