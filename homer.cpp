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

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAX=10e5+200;
int dp[MAX];
int m, n, t;
int mn, rmn;   

int solve(int r){
    if (r == 0) return 0;
    if (r < 0) {
        mn = min(mn, rmn);
        return -MAX;
    }
    if (dp[r] != -1) return dp[r];
    
    rmn = r;
    dp[r] = max(solve(r-m)+1, solve(r-n)+1);
    return dp[r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>m>>n>>t){
        memset(dp, -1, sizeof(dp));
        if (min(m, n) > t) {
            cout<<0<<" "<<t<<endl;
        } else {
            mn = MAX;
            int ans = solve(t);
            if (ans < 0) {
                memset(dp, -1, sizeof(dp));
                int nmn = mn;
                int nans = solve(t-nmn);
                cout<<nans<<" "<<nmn<<endl;
            } else {
                cout<<ans<<endl;
            }
        }
    }
}
