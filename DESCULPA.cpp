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

const int MAXC = 1000+50;
const int MAXF = 50+50;
const int MAXD = 25+50;

int dp[MAXF][MAXC];

int solve(int f, int c, vi t, vi d) {
    // debug(t, d);
    for (int i = 0; i <= f; i++) dp[i][0] = 0;
    for (int i = 0; i <= c; i++) dp[0][i] = 0;

    for (int i = 1; i <= f; i++) {
        for (int j = 1; j <= c; j++) {
            if (t[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]]+d[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[f][c];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (true) {
        int c, f; cin >> c >> f;
        if (c == 0 && f == 0) break;

        // w, v
        vi tam(f+1); vi desc(f+1);
        tam[0] = 0; desc[0] = 0;
        for (int i = 1; i <= f; i++) {
            int n, d; cin >> n >> d;
            tam[i] = n; desc[i] = d;
        }



        cout << "Teste " << t << endl;
        cout << solve(f, c, tam, desc) << endl << endl;

        t++;
    }
}
