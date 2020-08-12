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

const int MAXR = 110;
const int MAXC = 110;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int a, b; cin >> a >> b;
        int m[MAXR][MAXC] = {0};

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                cin >> m[i][j];
            }
        }

        // for (int i = 0; i < a+10; i++) {
        //     for (int j = 0; j < b+10; j++) {
        //         cout << m[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int dp[MAXR][MAXC] = {0};
        

        for (int i = 1; i <= a+1; i++) {
            for (int j = 1; j <= b+1; j++) {
                // debug(i, j);
                // debug(m[i-1][j], m[i-1][j-1], m[i-1][j+1]);
                dp[i][j] = max(dp[i-1][j] + m[i-1][j], max(dp[i-1][j-1]+m[i-1][j-1], dp[i-1][j+1]+m[i-1][j+1]));
                // debug(dp[i][j]);
            }
        }

        // for (int i = 1; i <= a+1; i++) {
        //     for (int j = 1; j <= b+1; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int mx = 0;
        for (int j = 0; j <= b+1; j++) {
            if (dp[a+1][j] > mx) mx = dp[a+1][j];
        }

        cout << mx << endl;
        
    }



}
