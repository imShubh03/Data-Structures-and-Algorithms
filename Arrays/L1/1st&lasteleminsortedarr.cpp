#include <bits/stdc++.h>

using namespace std;

int firstmost(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;  // To avoid overflow
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int lastocc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;  // To avoid overflow
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[6] = {1, 3, 3, 3,4, 7};
    
    int first = firstmost(arr, 6, 3);
    int last = lastocc(arr, 6, 3);
    cout << "First occurrence of 3 is at index: " << first << endl;
    cout << "Last occurrence of 3 is at index: " << last << endl;
    return 0;
}
