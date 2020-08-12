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

// UPSOLVING

// elephant info
struct e {
    int w, iq, id;

    e(int W=0, int IQ=0, int ID=0): 
    w(W), iq(IQ), id(ID) {};

    bool operator <(const e that) const {
        return w < that.w;
    }
};

const int MAX = 1010;
int n; int chosen, head; 
int dp[MAX];
int p[MAX];
e el[MAX];

void solve() {
    for (int i = 0; i < n; i++) {
        dp[i] = 1; p[i] = i;

        for (int j = 0; j < i; j++) {
            if (el[j].w < el[i].w && el[j].iq > el[i].iq && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }

        if (dp[i] > chosen) {
            chosen = dp[i];
            head = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int w, iq;
    n = 0;
    chosen = 1, head = 0;
    while (cin >> w >> iq) {
        el[n] = e(w, iq, n);
        n++;
    }

    sort(el, el + n);
    memset(dp, -1, sizeof(dp));
    solve();

    cout << chosen << endl;
    vi ans;
    while (p[head] != head) {
        ans.pb(head);
        head = p[head];
    }
    ans.pb(head);
    reverse(all(ans));
    for (int k = 0; k < chosen; k++) {
        cout << el[ans[k]].id + 1 << endl;
    }
}
