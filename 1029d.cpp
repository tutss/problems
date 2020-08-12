#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n, k; scanf("%i %i", &n, &k);
    int lg = 11;

    vi a(n);
    vi len(n);
    for (int i = 0; i < n; i++) scanf("%i", &a[i]);

    vll pw(lg);
    pw[0] = 1;
    for (int i = 1; i < lg; i++) {
        pw[i] = (pw[i-1] * 10) % k;
    }
    
    vi rems[lg];
    for (int i = 0; i < n; i++) {
        int j = a[i];
        while (j > 0) {
            len[i]++;
            j /= 10;
        }
        rems[len[i]].push_back(a[i]%k);
    }

    for (int i = 0; i < lg; i++) {
        sort(rems[i].begin(), rems[i].end());
    }
    

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < lg; j++)
        {
            ll rem = (ll(a[i]) * ll(pw[j])) % k;
            ll search = (k - rem) % k;
            auto l = lower_bound(rems[j].begin(), rems[j].end(), search);
            auto r = upper_bound(rems[j].begin(), rems[j].end(), search);
            ans += (r - l);
            if (len[i] == j && (rem + a[i]%k)%k == 0) --ans;
        }
    }
    cout << ans << endl;
}
