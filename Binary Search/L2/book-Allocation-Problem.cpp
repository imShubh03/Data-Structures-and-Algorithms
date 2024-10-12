#include<bits/stdc++.h>
using namespace std;

/* time :O(sumofarr - maxinarr + 1) * O(N)  space:O(1)
int func(vector<int>& arr, int pages) {
    int stud = 1;
    int studpages = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (studpages + arr[i] <= pages) {
            studpages += arr[i];
        } else {
            stud++;
            studpages = arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int i = low; i <= high; i++) {
        int cntstud = func(arr, i);
        if (cntstud == m) {
            return i;
        }
    }
    return -1;
}
*/

//optimised time:O(log(sum - max)) *O(n)
int func(vector<int>&arr, int pages){
    int stud = 1;
    int studpages =0;
    for(int i =0; i<arr.size(); i++){
        if(studpages + arr[i] <= pages){
            studpages += arr[i];
        }
        else{
            stud= stud+1;
            studpages = arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while(low <= high){
        int mid = (low + high)/2;

        int noofstud = func(arr, mid);

        if(noofstud > m){
            low = mid +1;
        }
        else{
            ans = mid;
            high = mid -1;
        }
    }
    return ans;
    
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin>>m;
    cout << findPages(arr, n, m) << endl;
    return 0;
}
