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

const int MAX=100000;

ll dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    for (int tt=0; tt<t; tt++){
        int e, f; cin>>e>>f;
        int n = f-e;
        
        vector<pii> c;
        int tc; cin>>tc;
        int diff = 0;
        for (int i=0; i<tc; i++){
            int v, w; cin>>v>>w;
            if (n%w!=0) diff++;
            c.push_back({v,w});
        }

        if (diff==tc) {
            cout << "This is impossible." << endl;
            return 0;
        }

        dp[0]=0;
        for (int i=1; i<=n; i++){
            vll mins;
            for (pii p:c){
                if (p.second<=i){
                    mins.push_back(min(dp[i-1]+ll(p.first), dp[i-p.second]+ll(p.first)));
                }
            }
            // debug(mins);

            ll mn = INT_MAX;
            for (ll j:mins) if(j<=mn) mn=j;

            dp[i]=mn;
            // debug(i, dp[i]);
        }

        cout << "The minimum amount of money in the piggy-bank is " << dp[n] << "." << endl;
    }

}
