#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> rotated = rotateArray(numbers, n);

    cout << "Array after rotating:\n";
    for (int i = 0; i < n; i++) {
        cout << rotated[i] << " ";
    }
    cout << endl;

    return 0;
}
