#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int a, b;
    scanf("%i %i", &a, &b);

    int factorial = 1;
    for (int i = 1; i <= min(a, b); i++) {
        factorial *= i;
    }

    printf("%i", factorial);
}
