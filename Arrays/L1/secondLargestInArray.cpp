#include <bits/stdc++.h>
using namespace std;

/*  brute force (only for +ve integers)  time:O(nlogn) space:O(1)
class Solution {
public:
    void secondlargest(int arr[], int n) {
        if (n == 0 || n == 1) {
            cout << -1 << " " << -1 << endl;  // edge case when only one element is present in array
            return;
        }
        sort(arr, arr + n);
        int small = arr[1];
        int large = arr[n - 2];
        cout << "Second smallest is " << small << endl;
        cout << "Second largest is " << large << endl;
    }
};
*/


/*  time:O(2n) space:O(1)
class Solution{
public:
    void secondlargest(int arr[], int n){
        if(n<2){
            return;
        }
        //get the max and min in arr
        int maxEle= INT_MIN;
        int minEle= INT_MAX;
        for(int i =0;i<n;i++){
            if(arr[i]>maxEle){
                maxEle=arr[i];
            }
            if(arr[i]<minEle){
                if(arr[i]<minEle){
                    minEle = arr[i];
                }
            }
        }

        //finding the second argest 
        int secLar=INT_MIN;
        int secSma = INT_MAX;
        for(int i =0;i<n;i++){
            if(arr[i]>secLar && arr[i]<maxEle){
                secLar=arr[i];
            }
            if(arr[i]<secSma && arr[i]>minEle){
                secSma=arr[i];
            }
        }
        cout << "Second largest element is " << secLar << endl;
        cout << "Second smallest element is " << secSma << endl;

    }
};
*/


//time :O(n) space:O(1)
class Solution{
public:
    void secondlargest(int arr[], int n){
        if(n<2){
            return;
        }
        int maxele = INT_MIN, secondMax = INT_MIN;
        int minele = INT_MAX, secondMin = INT_MAX;

        for (int i = 0; i < n; i++) {
            // Update largest and second largest
            if (arr[i] > maxele) {
                secondMax = maxele;
                maxele = arr[i];
            } else if (arr[i] > secondMax && arr[i] != maxele) {
                secondMax = arr[i];
            }

            // Update smallest and second smallest
            if (arr[i] < minele) {
                secondMin = minele;
                minele = arr[i];
            } else if (arr[i] < secondMin && arr[i] != minele) {
                secondMin = arr[i];
            }
        }
        cout << "Second largest element is " << secondMax << endl;
        cout << "Second smallest element is " << secondMin << endl;
    }
};


int main()
{
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution sol;
    sol.secondlargest(arr, n);
    return 0;
}