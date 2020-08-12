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

const int MAX = 2010;
const int INF = 0x3f3f3f3f;

const int NO_COLOR = 0;
const int BLUE = 1;
const int PINK = 2;

int op (int c) {
    if (c == BLUE) return PINK;
    return BLUE;
}

int oddcycle(int a, vi adj[], int bugs[], int marked[]) {
    queue<int> q;
    q.push(a);
    bugs[a] = BLUE;

    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        marked[u] = true;

        // debug(u, bugs[u], adj[u]);
        
        for (int i = 0; i < int(adj[u].size()); i++) {
            int v = adj[u][i];

            // debug(v, bugs[v]);
            if (u == v) {
                return true;
            }

            if (bugs[v] == NO_COLOR) {
                bugs[v] = op(bugs[u]);
                q.push(v);
            } else if (bugs[v] != NO_COLOR && bugs[v] == bugs[u]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    int cnt = 1;
    cin >> t;
    while (t--) {
        int bugs[MAX];
        int marked[MAX];
        vi adj[MAX];
        int n, steps;
        
        cin >> n >> steps;

        cout << "Scenario #" << cnt << ":" << endl;
        
        set<int> s;
        int a, b;
        for (int i = 0; i < steps; i++) {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
            s.insert(a);
            s.insert(b);
        }

        memset(bugs, 0, sizeof(bugs));
        memset(marked, 0, sizeof(bugs));
        
        bool same = false;
        for (auto it = s.begin(); it != s.end(); it++) {
            int u = *it;
            // debug(u);
            if (!marked[u]) {
                if (oddcycle(u, adj, bugs, marked)) {
                    cout << "Suspicious bugs found!" << endl;
                    same = true;
                    break;
                }
            }
        }

        if (!same) {
            cout << "No suspicious bugs found!" << endl;
        }

        cnt++;
    }
}
