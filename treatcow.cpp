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

const int MAX = 2001;
int dp[MAX][MAX];
vi v;

int solve(int i, int j, int a) {
    if (i >= j) return v[i]*a;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = max(solve(i+1, j, a+1)+v[i]*a, solve(i, j-1, a+1)+v[j]*a);

    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int t; cin >> t;
        v.pb(t);
    }

    memset(dp, -1, sizeof(dp));

    // greedy
    // int sum = 0;
    // int a = 1;
    // int i = 0; int j = n-1;
    // while (i <= j) {
    //     int x = v[i]; int y = v[j];
    //     if (x <= y) {
    //         sum += (x*a);
    //         i++;
    //     } else {
    //         sum += (y*a);
    //         j--;
    //     }
    //     a++;
    // }
    int sum = solve(0, n-1, 1);

    // for (int i = 0; i < n+3; i++) {
    //     for (int j = 0; j < n+3; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << sum << endl;
}
