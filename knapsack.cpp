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

const ll MAXW = 10e18;
const int MAXV = 8;
// item, weight
ll dp[MAXV+1][MAXW+1];

int knapsack(vll v, ll w, int n) {
    for (ll i = 0; i < w; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < 9; i++) {
        dp[i][0] = 0;
    }

    for (ll i = 0; i < w; i++) {
        for (int j = 1; i < 9; i++) {
            ll a = dp[j-1][w];
            ll b = 0LL;
            if (j < w) {
                b = max(dp[j-1][w], dp[j-1][])
            }
            dp[j][i] = max()
        }
    }
    

    if (n == 0 || w == 0) {
        return 0;
    } else if (n > w || v[n] == 0) {
        return knapsack(v, w, n-1);
    } else {
        int dontGet = knapsack(v, w, n-1);
        v[n] -= 1;
        int get = n + knapsack(v, w-n, n-1);
        int maxx = max(dontGet, get);
        return maxx;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll w; cin >> w;
    vll v(9);
    for (int i = 1; i <= 8; i++) {
        cin >> v[i];
    }

    ll maxx = knapsack(v, w, 8);
    cout << maxx << endl;
}
