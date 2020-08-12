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

const int INF = 0x3f3f3f3f;
const int MAX = 10e6 + 10;
int sum[MAX];
vi adj[MAX];
vi t(MAX);
vi ans;
int root;

int dfs(int u, int s) {
    sum[u] = t[u];
    for (int v : adj[u]) {
        sum[u] += dfs(v, s);
    }

    if (sum[u] == s && u != root) {
        ans.pb(u);
        return 0;
    }

    return sum[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    int sumTemp = 0;
    for (int i = 1; i <= n; i++) {
        int ai, ti; 
        
        cin >> ai >> ti;

        adj[ai].pb(i);
        
        t[i] = ti;
        
        if (ai == 0) {
            root = i;
        }

        sumTemp += ti;
    }
    
    int d = sumTemp/3;
    if (d * 3 != sumTemp) {
        cout << -1 << endl;
        return 0;
    }

    dfs(root, d);

    if (int(ans.size()) >= 2) {
        cout << ans[0] << " " << ans[1] << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
