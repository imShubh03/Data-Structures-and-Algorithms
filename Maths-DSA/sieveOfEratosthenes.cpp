#include <bits/stdc++.h>
using namespace std;


/*brute force  time: O(n sqrt(n))
class solution{
public:
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
    void sieveOFErasto(int n){
        for (int i = 2; i <= n; i++){
            if (isPrime(i)){
                cout << i << " ";
            }
        }
        cout << endl;
    }
};
*/

/*
//optimal: time O(n)
class solution{
    public:
    void sieveOFErasto(int n){
        vector<int>primes(n+1, 1);
        primes[0] = primes[1] = 0;
        for(int i =2;i<=n;i++){
            if(primes[i]==1){
                for(int j = 2*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }

        for(int i =2;i<=n;i++){
            if(primes[i]==1){
                cout<<i<<" ";
            }
        }
    }   
};
*/

//again optimising above appr
class solution{
    public:
    void sieveOFErasto(int n){
        vector<int>primes(n+1, 1);
        primes[0] = primes[1] = 0;
        for(int i =2;i*i<=n;i++){
            if(primes[i]==1){
                for(int j = i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }

        for(int i =2;i<=n;i++){
            if(primes[i]==1){
                cout<<i<<" ";
            }
        }
    }
    
};


int main()
{
    int n;
    cin >> n;
    solution sol;

    cout << "Prime numbers up to " << n << " are: ";
    sol.sieveOFErasto(n);

    return 0;
}
