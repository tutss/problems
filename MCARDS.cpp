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

int lis(vi v) {
    int n = int(v.size());
 
    vi dp(n);
    dp[0] = 1;
 
    int maxx = 1;
    for (int i = 1; i < n; i++) {
        int maxv = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) maxv = max(dp[j], maxv);
        }
        dp[i] = maxv+1;
        debug(dp[i]);
        maxx = max(maxx, dp[i]);
    }
 
    return maxx;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int colors, cards; cin >> colors >> cards;
    int n = colors*cards; 
 
    vector<pii> v(n);
    set<int> mn;
 
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }
 
    sort(v.begin(), v.end());
 
    do {
        vi vv(n);
        for (int i = 0; i < n; i++) vv[i] = v[i].second;
        debug(vv);
        mn.insert(lis(vv));
    } while (next_permutation(v.begin(), v.end()));
 
    cout << *(mn.end()) << endl;
}
