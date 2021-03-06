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

const int MAX = 10000;
const int INF = 0x3f3f3f3f;

// upsolving
struct turtle {
    int w, s;
    turtle(int W = 0, int S = 0): 
        w(W), s(S) {};

    bool operator <(const turtle that) const {
        if (s != that.s) return s < that.s;
        return w < that.w; 
    }
};

int dp[MAX];
turtle t[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    while (cin >> t[n].w >> t[n].s) {
        n++;
    }

    sort(&t[0], &t[n]);
    memset(dp, INF, sizeof(dp));

    int ans = 0;

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (t[i].s >= dp[j] + t[i].w) {
                dp[j+1] = min(dp[j+1], dp[j] + t[i].w);
                ans = max(ans, j+1);
            }
        }
    }

    cout << ans << endl;
}
