// first and lastelemnet in sorted arr given key
// any elem leftmost occurence index and right most occurence index show output
// think of binary seach
// dividing priblem into two parts first find the leftmost pccurence and then othe part right most occurence
#include <iostream>
#include <cmath>
using namespace std;
int firstmost(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}
int lastocc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid == key])
        {
            ans = mid;
            s = mid + 1;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}
int main()
{

    int even[6] = {1, 3, 4, 3, 3, 7};
    firstmost(even, 6, 3);
    lastocc(even, 6, 3);
    return 0;
}