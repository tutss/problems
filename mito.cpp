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

// const int MAX = 10e5+3;
const int streetSize = 3;
const int pad = 2;
const int blocked = -1;

vector<vi> blockSurround(vector<pair<int, char>> v, int rows, int cols) {
    vector<vi> grid(rows, vi(cols));
    for (auto p : v) {
        int pos = p.first; char c = p.second;
        int row; 
        int col = pos;
        if (c == 'S') row = 1;
        else if (c == 'M') row = 2;
        else row = 3;

        for (int i = row-1; i <= row+1; i++) {
            for (int j = col-1; j <= col+1; j++) {
                grid[i][j] = blocked;
            } 
        }
    }

    
    for () {
        for (int k : vv) {
            cout << k << " ";
        }
        cout << endl;
    } 

    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int size = streetSize + pad;
    
    vector<pair<int, char>> v(m);
    for (int i = 0; i < m; i++) {
        int pos; 
        char c; 
        cin >> pos >> c >> ws;
        v[i] = {pos, c};
    }
    debug(v);

    vector<vi> grid = blockSurround(v, size, n+pad);

    for (auto vv : grid) {
        for (int k : vv) {
            cout << k << " ";
        }
        cout << endl;
    } 

}
