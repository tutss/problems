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

const int MAX = 10e3 + 10;
const int INF = 0x3f3f3f3f;

vi first;
vi height;
vi tour;
vector<bool> visited;

vi seg;
int m;

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

void build(int v, int L, int R) {
    if (L == R) {
        seg[v] = tour[L];
    } else {
        int mid = (L + R) / 2;

        build(left(v), L, mid);
        build(right(v), mid + 1, R);
        
        int l = seg[left(v)];
        int r = seg[right(v)];
        
        seg[v] = (height[l] < height[r]) ? l : r;
    }
}

int query(int v, int l, int r, int i, int j) {
    if (l > j || r < i)
        return -1;
    if (l >= i && r <= j)
        return seg[v];
    int mid = (l + r) / 2;

    int segLeft = query(left(v), l, mid, i, j);
    int segRight = query(right(v), mid + 1, r, i, j);
    
    if (segLeft == -1) return segRight;
    if (segRight == -1) return segLeft;
    
    return (height[segLeft] < height[segRight]) ? segLeft : segRight;
}

///////////////////////////////////
void dfs(vi adj[], int u, int h) {
    visited[u] = true;
    height[u] = h;
    first[u] = int(tour.size());

    tour.pb(u);

    // debug(u, h, first[u]);
    for (int v : adj[u]) {
        // debug(u, v, bool(visited[v]));
        if (!visited[v]) {
            dfs(adj, v, h+1);
            tour.pb(u);
        }
    }
}
/////////////////////////////////
int lca(int u, int v) {
    
    int l = first[u];
    int r = first[v];

    if (l > r) {
        swap(l, r);
    }

    return query(1, 1, m, l, r);
}
////////////////////////////////
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    int cnt = 1;
    while (t--) {
        vi adj[MAX];
        
        int n; cin >> n;

        first.resize(n+10);
        visited.assign(n+10, false);
        height.resize(n+10);

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < a; j++) {
                int v;
                cin >> v;
                adj[i].pb(v);
            }
        }

        dfs(adj, 1, 0); // root = 1, height = 0

        m = int(tour.size());

        seg.resize(m*4+10);
        build(1, 1, m);

        cout << "Case " << cnt << ":\n";
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;

            int result = lca(l, r);
            cout << result << endl;
        }

        visited.clear();
        first.clear();
        height.clear();
        tour.clear();
        seg.clear();

        cnt++;
    }
}
