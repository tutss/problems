#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {

    while (true) {
        int n, k, m;
        scanf("%i %i %i", &n, &k, &m);

        if (n == -1 && k == -1 && m == -1) break;

        map<int, vector<int>> adj;
        map<int, int> locked;

        for (int i = 0; i < k; i++)
        {
            int a, b; scanf("%i %i", &a, &b); a--; b--;
            locked[b] = a;
        }

        if (locked.count(0)) {
            printf("N\n"); 
            break;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b; scanf("%i %i", &a, &b); a--; b--;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        
        if (int(adj[0].size()) == 0 || int(adj[n-1].size()) == 0) {
            printf("N\n"); 
            break;
        }

        vi reached(n);
        queue<int> q; q.push(0);
        reached[0] = 1;
        bool finished = false;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            bool checkAdj = true;
            bool islocked = locked.count(u) > 0 ? true : false;
            
            if (islocked) {
                int vk = locked[u];
                if (reached[vk] == 0) {
                    checkAdj = false;
                }
            }

            if (checkAdj) {
                for (int i = 0; i < int(adj[u].size()); i++)
                {
                    int v = adj[u][i];
                    bool isvlocked = locked.count(v) > 0 ? true : false;

                    if (reached[v] == 0 && !isvlocked) {
                        reached[v] = 1;
                        q.push(v);
                    }
                }
            }

            if (u == n-1 && checkAdj) {
                finished = true;
                printf("Y\n");
                break;
            }   
        }

        if (!finished) printf("N\n");
    }

    return 0;
}
