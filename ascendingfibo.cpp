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
const int MAX = 10e5 + 10e6 + 10;
const int MOD = 100000;

ll dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[1] = 0LL;
    dp[2] = 1LL;
    for(int i = 3; i < MAX; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % ll(MOD); 
    }

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int a, b;
        cin >> a >> b;
        
        cout << "Case " << q << ": ";
        
        vll fs;
        for (int k = a; k <= a+b; k++) {
            fs.pb(dp[k]);
        }
        int n = int(fs.size());

        // sort
        vi cntA(MOD+1, 0);
        int nc = int(cntA.size());

        for (int i = 0; i < n; i++) {
            cntA[fs[i]]++;
        }

        int k = 0;

        vi newfs;

        for (int j = 0; j <= nc; j++) {
            while (cntA[j]-- > 0) {
                if (k == 100) break;
                newfs.pb(j);
                k++; 
            }
        }

        // print
        for (int i = 0; i < int(newfs.size()); i++) {
            cout << newfs[i] << " ";
        }
        cout << endl;
    }
}
