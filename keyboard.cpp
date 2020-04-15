#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

vector<tupl> adj;

int hasCycle(int u, vi &visited, int parent) {
    cout << "parent " << parent << endl;
    for (int i = 0; i < int(visited.size()); i++) cout << visited[i] <<" ";
    cout << endl;

    visited[u] = true;
    for (auto v : adj[u]) {
        cout << "v: " << v << endl;
        cout << "visited v? " << visited[v] << endl;
        if (!visited[v]) {
            if (hasCycle(v, visited, u)) {
                return true;
            } else if (v != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%i", &t);

    for (int test = 0; test < t; test++) {
        string s;
        cin >> s;

        // set<int> unique;
        // for (char c : s) {
        //     unique.insert(c);
        // }

        // int unique_count = int(unique.size());

        int n = int(s.size());
        for (int i = 0; i < n-1; i++) {
            char a = s[i]; char b = s[i+1];
            // cout << "s[i]: " << s[i] << endl;
            // cout << s[i] - 'a' << endl;
            
            // else if (i > 0 && i < n-1) {
            //     adj[s[i]-'a'].insert(s[i+1]-'a');
            //     adj[s[i]-'a'].insert(s[i-1]-'a');
            // } else adj[s[i]-'a'].insert(s[i-1]-'a');
        }

        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (auto j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
        
        // bool hasCyc = false;

        // vi visited(n);
        // for (int u = 0; u < n; u++) {
        //     cout << "u: " << u << endl;
        //     if (!visited[u]) {
        //         bool hc = hasCycle(u, visited, -1);
        //         cout << "hc: " << hc << endl;
        //         if (hc) {
        //             printf("NO\n");
        //             hasCyc = true;
        //         }
        //     }
        // }
        
    }

    
}
