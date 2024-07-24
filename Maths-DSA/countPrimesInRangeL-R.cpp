#include <iostream>
#include <vector>
using namespace std;

/*   time : nearly O(n^3)
class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int n){
        if (n <= 1) return false;
        int cnt = 0;
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0){
                cnt++;
                if (n / i != i){
                    cnt++;
                }
            }
        }
        if (cnt == 2) return true;
        return false;
    }

    // Function to process multiple ranges and print primes
    void processQueries(vector<pair<int, int>>& queries) {
        int q = queries.size();
        for (int i = 0; i < q; i++) {
            int L = queries[i].first;
            int R = queries[i].second;
            int cnt = 0;

            cout << "Primes in range [" << L << ", " << R << "]: ";
            for (int j = L; j <= R; j++) { // Inclusive range
                if (isPrime(j)) {
                    cout << j << " ";
                    cnt++;
                }
            }
            cout << endl;
            cout << "Count of primes: " << cnt << endl;
        }
    }
};
*/

// optimised one time : nearly O(n^2)
class Solution {
public:
    // Function to create the sieve of Eratosthenes up to a given limit
    vector<bool> createSieve(int maxLimit) {
        vector<bool> sieve(maxLimit + 1, true);
        sieve[0] = sieve[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i <= maxLimit; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxLimit; j += i) {
                    sieve[j] = false;
                }
            }
        }

        return sieve;
    }

    // Function to process the queries
    void processQueries(const vector<pair<int, int>>& queries, const vector<bool>& sieve) {
        for (const auto& query : queries) {
            int L = query.first;
            int R = query.second;
            int cnt = 0;

            cout << "Primes in range [" << L << ", " << R << "]: ";
            for (int j = L; j <= R; ++j) {
                if (j >= 0 && j < sieve.size() && sieve[j]) {
                    cout << j << " ";
                    cnt++;
                }
            }
            cout << endl;
            cout << "Count of primes: " << cnt << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of queries: ";
    cin >> n;

    vector<pair<int, int>> queries(n);
    cout << "Enter the queries (L R):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Determine the maximum value in the queries to create the sieve up to this limit
    int maxLimit = 0;
    for (const auto& query : queries) {
        maxLimit = max(maxLimit, query.second);
    }

    Solution sol;
    vector<bool> sieve = sol.createSieve(maxLimit);

    // Call processQueries function
    sol.processQueries(queries, sieve);

    return 0;
}
