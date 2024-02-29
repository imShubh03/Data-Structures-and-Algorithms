#include <iostream>
#include <cmath>
using namespace std;
int getMax(int num[], int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (num[i] > max)
        {
            max == num[i];
        }
    }
    return max;
}
int getMin(int num[], int n)
{
    int min = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (num[i] < min)
        {
            min == num[i];
        }
    }
    return min;
}
int main()
{
    int size;
    cin >> size;
    int num[100];

    // input in arr
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    getMax(num, size);
    getMin( num, size);
    return 0;
}