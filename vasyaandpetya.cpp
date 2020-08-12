#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

bitset<10000> bs;
vi primes;

void sieve(int n) {
    bs.set();
    bs[0] = bs[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (bs[i]) {
            primes.push_back(i);
            
            for (int j = i*i; j <= n; j *= i) {
                bs[j] = 0;
                primes.push_back(j);
            }
            
            for (int j = i*i; j <= n; j += i) {
                bs[j] = 0;
            }
        }
    }
}

int main() {
    int n;
    scanf("%i", &n);

    sieve(n);

    printf("%i\n", int(primes.size()));
    for (int i = 0; i < int(primes.size()); i++) {
        printf("%i ", primes[i]);
    }
    
    
    
}
