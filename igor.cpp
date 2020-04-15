#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

const char blocked = '*';
const int MAX = 1000*1000;

vector<char> grid;

vi adj[MAX];
bool found = false;

queue<int> q;
vi p;
vi path;

void constructPath(int u, int igor) {
    if (u == igor) {
        path.push_back(igor);
        return;
    }
    constructPath(p[u], igor);
    path.push_back(u);
}

int bfs(int v, int n) {
    vi dist(n, INT_MAX); dist[v] = 0;
    q.push(v);
    while (!q.empty()) {
        int k = q.front(); q.pop();
        if (grid[k] == 'T') return 1;
        for (int i = 0; i < int(adj[k].size()); i++) {
            int u = adj[k][i];
            if (dist[u] == INT_MAX) {
                dist[u] = dist[k]+1;
                p[u] = k; q.push(u);
            }
        }
    }

    return -1;
}

int main() {
    int rows, m, n;
    scanf("%i %i", &rows, &m);
    n = rows * m;
    p.resize(n);

    int igorPos, workPos;
    
    int count = 0;
    while (int(grid.size()) != n) {
        char inp; scanf("%c", &inp);
        if (inp == 'S') igorPos = count; 
        if (inp == 'T') workPos = count;
        
        if (!isspace(inp)) {
            grid.push_back(inp);
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (grid[i] != blocked) {
            if (i + m < n) {
                if (grid[i+m] != blocked) adj[i].push_back(i+m);
            }
            if (i - m >= 0) {
                if (grid[i-m] != blocked) adj[i].push_back(i-m);
            }
            if ((i%m)+1 < m) {
                if (grid[i+1] != blocked) adj[i].push_back(i+1);
            }
            if (i%m != 0) {
                if (grid[i-1] != blocked) adj[i].push_back(i-1);
            }
        }
    }
    
    int search = bfs(igorPos, n);

    if (search == -1) {
        printf("NO\n");
        return 0;
    }

    constructPath(workPos, igorPos);

    // cout << endl;
    // for (int i = 0; i < int(path.size()); i++) {
    //     printf("%i ", path[i]);
    // }
    // cout << endl;
    

    int igorCol = igorPos % m;
    int igorRow = igorPos / m;
    int cturns = 0, rturns = 0;
    
    // transitions
    if (igorCol == 0) igorCol = 1;
    else if (igorCol == m-1 && m-2>=0) igorCol = m - 2;

    if (igorRow == 0) igorRow = 1;
    else if (igorRow == rows-1 && rows-2>=0) igorRow = rows - 2;

    bool atCol = false;
    bool outCol = false;
    bool returnedCol = false;

    bool atRow = false;
    bool outRow = false;
    bool returnedRow = false;
    for (int i = 0; i < int(path.size()); i++) {
        // printf("path i: %i\n", path[i]);
        if (path[i]%m == igorCol) {
            // cturns++;
            // printf("\t| at same col\n");
            if (returnedCol) returnedCol = false;
            if (outCol) {
                // printf("\t| returned col\n");
                returnedCol = true;
                outCol = false;
                cturns++;
            }
            atCol = true;
        } else {
            if (atCol && path[i]%m != igorCol) {
                // printf("\t| out col\n");
                outCol = true;
                atCol = false;
                returnedCol = false;
            }
        }

        // printf("outCol: %i | returnedCol: %i | atCol: %i\n", outCol, returnedCol, atCol);

        if (path[i]/m == igorRow) {
            if (outRow) {
                returnedRow = true;
                outRow = false;
                rturns++;
            }
            atRow = true;
        } else {
            if (atRow && path[i]/m != igorRow) {
                outRow = true;
                atRow = false;
                returnedRow = false;
            }
        }

        // printf("outRow: %i | returnedRow: %i | atRow: %i\n", outRow, returnedRow, atRow);
    }

    // printf("rturns: %i, cturns: %i\n", rturns, cturns);

    if (cturns>=2 || rturns>=2 || rturns+cturns>2) printf("NO\n");
    else printf("YES\n");
}
