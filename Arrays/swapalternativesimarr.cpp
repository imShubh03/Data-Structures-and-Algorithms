#include<bits/stdc++.h>

using namespace std;
void alternateswap(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int reverse[7] = {2, 4, 6, 7, 9, 5, 8};
    alternateswap(reverse, 7);

    print(reverse, 7);

    return 0;
}