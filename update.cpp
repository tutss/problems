#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;

int main() {
    int t; scanf("%i", &t);
    for (int i =0; i < t; i++) {
        int n, u; scanf("%i %i", &n, &u);

        vector<int> v(n+1);

        int l, r, val;
        for(int j=0; j<u; j++){
            scanf("%i %i %i", &l, &r, &val);
            v[l] += val;
            v[r+1] -= val;
        }

        vi updated(n);
        for (int j = 0; j < n; j++) {
            if (j == 0) updated[j] = v[j];
            else updated[j] = v[j] + updated[j-1];
        }

        int q; scanf("%i",&q);
        for (int j=0;j<q;j++) {
            int qi; scanf("%i", &qi);
            printf("%i\n", updated[qi]);
        }
    }
}
