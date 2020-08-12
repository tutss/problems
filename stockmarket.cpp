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

const int INF = 0x3f3f3f3f;
const int MAX= 2*10e5+10;

// dp[i] max dinheiro no dia i
int dp[MAX][2];
int stockPrice[MAX];
int n, c;

int solve(int i, int bs) {    
    if (i == n) return 0;
    if (dp[i][bs] != -1) return dp[i][bs];

    // mantem, vende e compra
    dp[i][1] = max(solve(i+1, 1), solve(i+1, 0) + stockPrice[i]);
    dp[i][0] = max(solve(i+1, 0), solve(i+1, 1) - (c+stockPrice[i]));

    return dp[i][bs];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>c) {
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            cin >> stockPrice[i];
        }

        dp[n][0] = dp[n][1] = 0;

        cout << solve(0, 0) << endl;
    }

}
