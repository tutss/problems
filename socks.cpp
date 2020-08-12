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

#define all(x) (x).begin(), (x).end()
#define bsearch(v, x) binary_search(all(v), x)

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAX = 200001;

int c[MAX], mxc[MAX];
int sz[MAX], p[MAX];
map<int, int> cmp_col[MAX];

int root(int u){
    if (u==p[u]) return u;
    return p[u]=root(p[u]);
}

int union_(int a, int b){
    a=root(a);
    b=root(b);
    
    if (a==b) return false;
    if (sz[a]<sz[b]) swap(a,b);
    
    p[b]=a;
    sz[a]+=sz[b];

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k; cin>>n>>m>>k;
    
    for (int i=0; i<MAX; i++){
        sz[i]=1;
        p[i]=i;
    }

    for (int i=1; i<=n; i++){
        cin >> c[i];
    }

    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        union_(a, b);
    }

    // versao da aula
    set<int> roots;
    for (int i=1; i<=n; i++){
        int x=root(i);
        cmp_col[x][c[i]]++; // cor c[i] esta no componente
        if (cmp_col[x][c[i]]>mxc[x]) mxc[x]=cmp_col[x][c[i]]; // cor que mais aparece na componente
        roots.insert(x); // contem as raizes de cada componente
    }

    int ans = 0;
    for (auto i : roots) ans+=sz[i]-mxc[i];

    cout << ans << endl;
}
