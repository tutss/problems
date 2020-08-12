#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAXW = 10e5+3;

ll dp[MAXW];

ll solve(int wg, int c, vi w, vi v) {
    for (int i = 0; i < wg+3; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= wg; i++) {
        for (int j = 0; j < c; j++) {
            if (w[j] <= i) {
                dp[i] = min(dp[i-w[j]]+v[j], dp[i]);
            }
        }
    }

    if (dp[wg] == INT_MAX) return -1;
    else return dp[wg];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    for (int tt = 0; tt < t; tt++) {
        int mn, mx; cin >> mn >> mx;
        int tcoins; cin >> tcoins;

        vi v(tcoins); vi w(tcoins);
        for (int i = 0; i < tcoins; i++) {
            cin >> v[i] >> w[i];
        }

        ll mxc = solve(mx-mn, tcoins, w, v);
        if (mxc >= 0) {
            printf("The minimum amount of money in the piggy-bank is %lld.\n", mxc);
        } else {
            printf("This is impossible.\n");
        }
    }
}
