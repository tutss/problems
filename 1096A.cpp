#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        ll l, r; scanf("%lld %lld\n", &l, &r);
        printf("%lld %lld\n", l, 2*l);
    }
    
}
