#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int MAX = 1e4;

void floydWarshall (vi graph[], int n) {  
    int dist[n][n], i, j, k;  
  
    for (i = 0; i < n; i++)  
        for (j = 0; j < n; j++)  
            dist[i][j] = graph[i][j];  

for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    map<int, int> distNumb;
    for (k = 0; k < n; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            for (j = 0; j < n; j++)  
            {  
                if (dist[i][j] != 0) distNumb[dist[i][j]] += 1;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];  
                }
            }  
        }  
    }  
    
    for (auto e : distNumb) {
        cout << e.first << " | " << e.second << endl;
    }
    cout << endl;
}  

int main() {
    int n, x, y; scanf("%i %i %i", &n, &x, &y);
    vector<int> adj[MAX];
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i+1);
    }
    adj[x].push_back(y);
    // floydWarshall(adj, n);
    int dist = n;
    while (dist >= 0) {
        for (int i = 0; i < n; i++)
        {
            int v = i;
            for (int j = 0; j < count; j++)
            {
                /* code */
            }
            
        }
        
    }

}
