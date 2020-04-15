#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int k2, k3, k5, k6; scanf("%i %i %i %i", &k2, &k3, &k5, &k6);

    int sum = 0;
    while (k2 != 0 && k5 != 0 && k6 != 0) {
        k2--; k5--; k6--;
        sum += 256;
    }

    while (k3 != 0 && k2 != 0) {
        k3--; k2--;
        sum += 32;
    }

    printf("%i", sum);
}
