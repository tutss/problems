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

const int MAX = 510;
const int MAXF = 9;
const int INF = 0x3f3f3f3f;

// upsolving

int bcktrk[MAX][MAXF][2];
int dp[MAX][MAX];
int c[MAX][MAXF];
vector<string> fname = {"front", "back", "left", "right", "top", "bottom"};
int n;

int opposite(int f) {
    if (f % 2 == 0) return f+1;
    return f-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        if (t > 1) cout << endl;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> c[i][j];
                dp[i][j] = 1;
                bcktrk[i][j][0] = bcktrk[i][j][1] = 0;
            }
        }

        int ans[2] = {1, 0};
        for (int i = 1; i <= n; i++) {
            for (int fi = 0; fi < 6; fi++) {
                for (int j = i-1; j >= 1; j--) {
                    for (int fj = 0; fj < 6; fj++) {
                        if (c[i][fi] == c[j][opposite(fj)] && dp[j][fj] + 1 > dp[i][fi]) {
                            dp[i][fi] = dp[j][fj] + 1;
                            bcktrk[i][fi][0] = j;
                            bcktrk[i][fi][1] = fj;

                            if (dp[i][fi] > dp[ans[0]][ans[1]]) {
                                ans[0] = i;
                                ans[1] = fi;
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << t << endl;
        cout << dp[ans[0]][ans[1]] << endl;

        vector<pii> bck;

        while (ans[0] != 0) {
            bck.pb(pii(ans[0], ans[1]));
            int id = bcktrk[ans[0]][ans[1]][0];
            int face = bcktrk[ans[0]][ans[1]][1];
            ans[0] = id; ans[1] = face;
        }

        reverse(all(bck));

        for (pii p : bck) {
            cout << p.first << " " << fname[p.second] << endl;
        }
        t++;
    }

}
