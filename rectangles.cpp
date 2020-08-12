#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n,m; scanf("%i %i\n", &n, &m);

    vi row_white(n); vi row_black(n);
    vi col_white(m); vi col_black(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int elem; scanf("%i", &elem);
            if (elem) {
                row_white[i]++;
                col_white[j]++;
            } else {
                row_black[i]++;
                col_black[j]++;
            }
        }
    }

    ll rw = 0; ll rb = 0;
    for (int i = 0; i < n; i++) {
        rw += (1LL << row_white[i]) - 1;
        rb += (1LL << row_black[i]) - 1;
    }

    ll cw = 0; ll cb = 0;
    for (int j = 0; j < m; j++) {
        cw += (1LL << col_white[j]) - 1;
        cb += (1LL << col_black[j]) - 1;
    }

    cout << (cw+rw+cb+rb) - n*m << endl;
}
