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

#define all(x) (x).begin(), (x).end()
#define bsearch(v, x) binary_search(all(v), x)
#define pb push_back

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAX = 10e3 + 10;
const int INF = 0x3f3f3f3f;

ll dp[MAX];
ll v[MAX];
int n;

ll solve(ll i) {
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = max(solve(i+1), solve(i+2)+v[i]);

    return dp[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    int cnt = 1;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << "Case " << cnt << ": ";
        
        if (n == 0) cout << 0 << endl;
        else cout << solve(0) << endl;

        cnt++;
        memset(v, 0, sizeof(v));
    }

}
