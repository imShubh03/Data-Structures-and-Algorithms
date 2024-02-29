// for bin sear elem should be in monotonic funcn (kind of increasing order)
// first find mid  elem and then compare with given key
// if equL RETURN THAT index if not then see key in which part of 2 halves
// again repeat process of mid elem and then compare as we have 2 parts of arrays afteer dividing in first time
#include <iostream>
#include <cmath>
using namespace std;
int binarysearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }
        // right side of arr
        if ( key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        // updating mid elem
        mid = (start + end) / 2;
    }
    return -1;
}
int main()
{

    int even[6] = {1, 3, 5, 7, 9, 10};
    int odd[5] = {2, 4, 5, 6, 7};
    int result = binarysearch(even, 6, 9);
    cout << result << endl;
    return 0;
}