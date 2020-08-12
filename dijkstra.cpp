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
const int MAX = 1+10e4;

int dijkstra(int s, int e, vector<pii> adj[], int dist[]) {
    dist[s] = 0;

    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({s, 0});
    
    while (!pq.empty()) {
        pii p = pq.top();
        int u = p.first;
        pq.pop();

        for (int i = 0; i < int(adj[u].size()); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(adj[u][i]);
            }
        }
    }

    return dist[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int V, E;
        vector<pii> adj[MAX];
        int dist[MAX];
        
        memset(dist, INF, sizeof(dist));

        cin >> V >> E;
        for (int e = 0; e < E; e++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
        }
        
        int s, e;
        cin >> s >> e;

        int len = dijkstra(s, e, adj, dist);
        if (len != INF) cout << len << endl;
        else cout << "NO" << endl;

    }

}
