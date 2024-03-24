#include<bits/stdc++.h>

using namespace std;
// given are array of 0s and 1s we have to sort such that all
//  0s on one side and all 1s on other

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
void sortedarray(int arr[], int n)
{
    int right = 0, left = n - 1;

    while (right < left)
    {

        while (arr[left] == 0 && left < right)
        {
            left++;
        }

        while (arr[right] == 0 && left < right)
        {
            right--;
        }
        // untill here only condition is
        // arr[left] == 1 & arr[right] == 0
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[8] = {1, 0, 1, 0, 0, 1, 1, 0};
    sortedarray(arr, 8);
    printarray(arr, 8);
    return 0;
}