#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

vi adj;

int dfs(int v) {
    if (adj[v] == -2) return 1;
    return dfs(adj[v]) + 1;
}

int main() {
    int n; scanf("%i", &n);

    for (int i = 0; i < n; i++) {
        int pi; scanf("%i", &pi);
        adj.push_back(pi-1);
    }

    int d = 1;
    for (int i = 0; i < n; i++) {
        d = max(dfs(i), d);
    }

    printf("%i", d);
}
