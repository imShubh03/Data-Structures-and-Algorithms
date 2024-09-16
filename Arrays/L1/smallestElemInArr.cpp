#include <bits/stdc++.h>
using namespace std;


int findSmallest(vector<int>& arr){
    int small = arr[0];
    for(int i =1; i<arr.size(); i++){
        if(arr[i] < small){
            small = arr[i];
        }
    }
    return small;
}

int main() {
    int n;
    cin >> n;

    if(n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int smallest = findSmallest(arr);
    cout << smallest << endl;

    return 0;
}
