#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find prime factors without repetitions
vector<int> primeFactors(int n) {
    vector<int> factors;

    // Check for factor 2
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    // Check for odd factors from 3 to sqrt(n)
    for (int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // If n is still greater than 2, then n itself is a prime factor
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> factors = primeFactors(n);

    cout << "Prime factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
