#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define visited 1
#define unvisited 0

// [0,1,0....]
vi vertices;
// (x) -> [x1,...]
map<int, vi> adjList;

void dfs(int u) {
    vertices[u] = visited;
    for (int j = 0; j < int(adjList[u].size()); j++) {
        int adjVert = adjList[u][j];
        if (vertices[adjVert] == unvisited) {
            vertices[adjVert] = visited;
            dfs(adjVert);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    
    if (n == 1 && m == 1) {
        printf("%d", 1);
        return 0;
    }
    int size = n*m;
    vertices.resize(size);

    int cc = 0;
    char grid[size];
    
    for (int i = 0; i < size; i++) cin >> grid[i];
    
    for (int i = 0; i < size; i++) {
        char dir = grid[i];

        if (dir == 'N') {
            adjList[i].push_back(i-m);
        } else if (dir == 'S') {
            adjList[i].push_back(i+m);
        } else if (dir == 'W') {
            adjList[i].push_back(i-1);
        } else if (dir == 'E') { 
            adjList[i].push_back(i+1);
        }

        if (i-m >= 0) {
            if (grid[i-m] == 'S') {
                adjList[i].push_back(i-m);
            }
        }

        if (i+m < size) {
            if (grid[i+m] == 'N') {
                adjList[i].push_back(i+m);
            }
        }

        if (i+1 < n*m) {
            if (grid[i+1] == 'W') {
                adjList[i].push_back(i+1);
            }
        }

        if (i-1 >= 0) {
            if (grid[i-1] == 'E') {
                adjList[i].push_back(i-1);
            }
        }
    }
    
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        int v = it->first;
        if (vertices[v] == unvisited) {
            dfs(v);
            cc++;
        }
    }
    
    printf("%d\n", cc);
}