#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

const int MAX = 29;

vi path;

int hasCycle(int u, vi &visited, int parent, vector<set<int>> &adj) {

    visited[u] = true;
    path.push_back(u);

    if (int(adj[u].size()) > 0) {
        for (auto v : adj[u]) {
            cout << "\tv: " << v << endl;
            if (!visited[v]) {
                if (hasCycle(v, visited, u, adj)) {
                    return true;
                }
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

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        vector<set<int>> adj(MAX);
        cout << "s: " << s << endl;

        int n = int(s.size());
        set<char> unique;
        for (int i = 0; i < n-1; i++) {
            unique.insert(s[i]);
            if (!(adj[s[i+1]-'a'].count(s[i]-'a') > 0))
                adj[s[i]-'a'].insert(s[i+1]-'a');
        }

        int leaf = s[0]-'a';
        bool end = false;
        for (int i = 0; i < MAX; i++)
        {
            if (end) break;
            if (int(adj[i].size()) > 0) {
                for (auto j : adj[i]) {
                    if (int(adj[j].size()) == 0) {
                        leaf = j;
                        end = true;
                        break;
                    }
                }
            }
        }
        

        vi visited(MAX);
        if (!hasCycle(s[0]-'a', visited, -1, adj)) {
            cout << "YES\n";
            
            for (int i = 0; i < int(path.size()); i++)
            {
                printf("%i ", path[i]);
            }

            cout << endl;
            
            
            // string print = "";
            // for (char c : unique) {
            //     print += c;
            //     alphabet[c-'a'] = 'X';
            // }

            // printf("%s", print.c_str());
            // for (char c : alphabet) {
            //     if (c != 'X') printf("%c", c);
            // }
            // printf("\n");
        } else {
            cout << "NO\n";
        }

        path.clear();
                
    }
    
}
