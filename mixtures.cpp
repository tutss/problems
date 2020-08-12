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

const int MAX = 103;
ll p[MAX];
ll acc[MAX];
ll dp[MAX][MAX];
int n;

ll sum(int i, int j) {
    ll s = 0;
    while (i <= j) {
        s+=p[i];
        s%=100;
        i++;
    }
    return s;
}

ll solve(int i, int j) {
    if (j <= i) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j]=INT_MAX;
    for (int k=i; k<=j; k++) {
        ll s1 = sum(i, k);
        ll s2 = sum(k+1, j);
        
        dp[i][j] = min(solve(i, k)+solve(k+1, j)+(s1*s2), dp[i][j]);
    }

    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin>>n) {
        memset(p, 0, sizeof(p));
        memset(dp, -1, sizeof(dp));

        for (int i=0; i<n; i++) {
            cin >> p[i];
        }

        // memset(acc, 0, sizeof(acc));
        // acc[0]=0;
        // acc[1]=p[0]%100;
        // for (int i=2; i<=n; i++) {
        //     acc[i] += (p[i-1]+acc[i-1]);
        //     acc[i] %= 100;
        // }
        // debug(acc[2]);
        
        ll ans = solve(0, n-1);
        cout << ans << endl;
    }
}