#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    ll n;
    scanf("%lld", &n);

    ll total = (n * (n+1)) / 2;
    printf("%lld", total - (n-1));
}
