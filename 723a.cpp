#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int a, b, c; scanf("%i %i %i", &a, &b, &c);
    vi v = {a, b, c};
    sort(v.begin(), v.end());

    printf("%i", v[1]-v[0] + v[2]-v[1]);
}
