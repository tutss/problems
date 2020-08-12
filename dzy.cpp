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

// class from Competitive Programming 3, pg 54
class UnionFind {
    public:
        vi p, rank;
        map<int, int> set_numElem;
        
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++) p[i] = i; 
        }
        
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }
        
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j); 
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; 
            }
        } 
    } 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    UnionFind u(n+1);

    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        u.unionSet(a, b);
    }

    ll cc = 0;
    for (int i = 1; i <= n; i++) {
        if (u.findSet(i) == i) cc++;
    }

    cout << (1LL<<(n-cc)) << endl;
}
