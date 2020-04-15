#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n;
    scanf("%i", &n);

    int count = 0;
    vi v(n+1);
    for (int i = n; i > 0; i--) {
        count++;
        if (count == i) {
            printf("-1");
            return 0;
        }
        v[i] = i;
    }
    
    for (int i = n; i > 0; i--) {
        printf("%i ", v[i]);
    }
}
