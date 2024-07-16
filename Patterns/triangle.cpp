/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/
#include <iostream>
using namespace std;

void triangle(int n)
{
    // Print a right-angled triangle pattern with each line displaying the current row number
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the triangle: ";
    cin >> n;
    triangle(n);
    return 0;
}
