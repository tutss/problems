#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

void sieve(vi& primes, int lim) {
    bool marked[lim+1] = {0};

    for (int p = 2; p <= lim; ++p) {
        if (marked[p]==false) {
            primes.emplace_back(p);
            for (int j = p; j <= lim; j+=p)
                marked[j] = true;
        }
    }
}

// seen on geeksforgeeks
void segsieve(int a, int b) {
        int limit = floor(sqrt(b))+1;
        vi primes;
        
        // sieve
        sieve(primes, limit);
        
        // segmented sieve
        int n = b - a + 1;
        bool markedRange[n+1] = {0};

        int psize = int(primes.size());
        for (int i = 0; i < psize; i++) {
            int low = floor(a / primes[i]) * primes[i];
            if (low < a) low += primes[i];
            if (low == primes[i]) low += primes[i];

            for (int j = low; j <= b; j+=primes[i])
                markedRange[j-a] = true;
        }

        for (int i = a; i <= b; i++)
            if (!markedRange[i-a] && i != 1) 
                printf("%i\n", i);
    
}

int main() {
    int t; scanf("%i", &t);

    for (int i = 0; i < t; i++)
    {
        int a, b; scanf("%i %i", &a, &b);

        segsieve(a, b);
        
        if (i+1 != t) printf("\n");
    }

    return 0; 
}
