#include <bits/stdc++.h>
using namespace std;

// MAX HEAP
void heapify(int arr[], int n, int i)
{
    // for max heap largest ele is i
    int largest = i;
    // put largest eleme in correct posn
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    // check if largest is updated
    // initi largest = i
    //  if largest is updated then its not equal to i and largest is pointed to correct posn so swap
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        // now check if any elem to be moved in correct posn by recursive call
        heapify(arr, n, largest);
    }   
}




/*
// MIN HEAP
void heapify(int arr[], int n, int i)
{
    // for max heap largest ele is i
    int smallest = i;
    // put largest eleme in correct posn

    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    // check if largest is updated
    // initi largest = i
    //  if largest is updated then its not equal to i and largest is pointed to correct posn so swap
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        // now check if any elem to be moved in correct posn by rec7ursive call
        heapify(arr, n, smallest);
    }
    
}
*/



int main()
{
    // not considering 0th elem
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "printing array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
