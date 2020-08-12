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

// upsolving
const int MAX = 1e3+10;
const int MAXK = 12;
const int INF = 0x3f3f3f3f;

int n, m, K;
int dp[MAX][MAX][MAXK][2];
char s[MAX], t[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d%d", &n, &m, &K);
    scanf("%s", s+1);
    scanf("%s", t+1);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= K; k++) {
                for (int l = 0; l <= 1; l++) {
                    dp[i][j][k][l] = -INF;
                }
            }
        }
    }

    for (int i = 0; i <= max(n, m); i++) {
        dp[i][0][0][0] = dp[0][i][0][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= K; k++) {
                for (int l = 0; l <= 1; l++) {
                    if (s[i] == t[j]) {
                        if (l != 0) 
                            dp[i][j][k][l] = max(dp[i][j][k][l], dp[i-1][j-1][k][l]+1);
                        else if (k != 0) 
                            dp[i][j][k][1] = max(dp[i][j][k][1], dp[i-1][j-1][k-1][l]+1);
                    }
                    dp[i][j][k][0] = max(dp[i][j][k][0], max(dp[i-1][j][k][l], dp[i][j-1][k][l]));
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= max(n, m); i++) {
        for (int k = 0; k <= K; k++) {
            for (int l = 0; l <= 1; l++) {
                ans = max(max(ans, dp[n][i][k][l]), dp[i][m][k][l]);
            }
        }
    }

    cout << ans << endl;
}
