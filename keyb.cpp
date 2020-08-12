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

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int len = 0;
bool validDFS = true;

void constructAlpha(string &alphabet) {    
    for (int i = 0; i < 26; i++) {
        alphabet+='a'+i;
    }
}

void constructOutput(string &alphabet, string chosen) {
    for (char c : chosen) {
        alphabet[c-'a'] = 'X';
    }
}


void constructPath(char u, int n, string &path, map<char, char> p) {
    len++;
    if (len >= n) {
        path+=u;
        return;
    }
    constructPath(p[u], n, path, p);
    path+=u;
}

void dfs(char u, map<char, set<char>> adj, map<char, bool> &visited, map<char, char> &p) {
    // debug(validDFS, u);
    // debug(p);
    visited[u] = true;
    for (char v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            p[u] = v;
            dfs(v, adj, visited, p);
        } else if (visited[v] && p[v] != u) {
            validDFS = false;
        }
    }
    // validDFS = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t >> ws;
    for (int tt = 0; tt < t; tt++) {
        string s; cin >> s >> ws;
        // debug(s);
        
        string alphabet = "";
        constructAlpha(alphabet);

        set<char> un;
        for (char c : s) un.insert(c);

        if (int(un.size())==1 || int(un.size())==2) {
            string p = ""; 
            for (auto it = un.begin(); it != un.end(); it++) {
                p += *it;
            }

            constructOutput(alphabet, p);
            cout << "YES" << endl;
            cout << p;
            for (char c : alphabet) {
                if (c != 'X') cout << c;
            }
            cout << endl;
            continue;
        }

        map<char, set<char>> adj;

        for (int c = 0; c < int(s.size()); c++) {
            if (c == 0) {
                adj[s[c]].insert(s[c+1]);
            } else if (c < int(s.size())-1 && c > 0) {
                adj[s[c]].insert(s[c+1]);
                adj[s[c]].insert(s[c-1]);
            } else {
                adj[s[c]].insert(s[c-1]);
            }
        }
        
        vector<char> leaves;
        int count = 0;
        bool impossible = false;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            char key = it->first;
            count++;
            if (int(adj[key].size()) == 1) leaves.push_back(key);
            if (int(adj[key].size()) > 2) impossible = true;
        }
        
        bool need_to_break = false;
        if (int(leaves.size()) == 0 || impossible) {
            cout << "NO" << endl;
        } else {
            vector<string> paths;
            map<char, bool> visited;
            map<char, char> p;
            for (char l : leaves) {
                string path = "";
                
                if (need_to_break) break;

                dfs(l, adj, visited, p);
                if (!validDFS) {
                    cout << "NO" << endl;
                    need_to_break = true;
                } else {
                    constructPath(l, count, path, p);
                    paths.push_back(path);
                }
                visited.clear();
                p.clear();
                len = 0;
                validDFS = true;
            }

            sort(paths.begin(), paths.end(), [](string a, string b){
                return int(a.size()) < int(b.size());
            });

            if (!need_to_break) {
                cout << "YES" << endl;
                string chosen = paths[0];
                
                constructOutput(alphabet, chosen);

                cout << chosen;
                for (char c : alphabet) {
                    if (c != 'X') cout << c;
                }
                cout << endl;
            }
            
        }
    }

}
