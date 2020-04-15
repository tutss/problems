#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

const int MAX = 3*10e5;

map<int, set<int>> adj;
vi reachedSize;

int fl;
int bee;

void dfs(int u, int initial) {
    reachedSize[u] = 1;
    for (auto i : adj[u]) {
        if (i != initial) {
            int v = i;
            dfs(v, u);
            reachedSize[u] += reachedSize[v];
        }
    }
}

int main() {
    int n;
    scanf("%i", &n);

    ll paths = ll(n*ll(n-1));
    reachedSize.resize(n+1);
    
    scanf("%i", &fl);
    scanf("%i", &bee);

    for (int i = 0; i < n; i++) {
        int a,b;
        scanf("%i %i\n", &a, &b);

        adj[a].insert(b);
        adj[b].insert(a);
    }

    dfs(bee, 0); // root at bee
    ll flSubtrees = reachedSize[fl];
    
    // printf("%i %i\n", flSubtrees, paths)
    // for (int i = 1; i <= n; i++) printf("%i ", reachedSizes[i]);
    // printf("\n");

    dfs(fl, 0); // root at fl
    ll beeSubtrees = reachedSize[bee];
    
    printf("%lld\n", paths - beeSubtrees*flSubtrees);
}
