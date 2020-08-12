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

const int MAXN = 5010;
const int MAXK = 1010;
const int INF = 0x3f3f3f3f;

int dp[MAXN][MAXK];
int chops[MAXN];
int n, K;

// upsolving

int solve(int i, int k){
    if (k == 0) return 0;
    if (i >= n || (3*k + i) > n) return INF;
    if (dp[i][k] != -1) return dp[i][k];

    dp[i][k] = min(solve(i+1, k), solve(i+2, k-1) + (chops[i+1] - chops[i])*(chops[i+1] - chops[i]));
    
    return dp[i][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;

    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> K >> n;
        K += 8;

        for (int i = 0; i < n; i++) {
            cin >> chops[i];
        }

        cout << solve(0, K) << endl;
    }

}
