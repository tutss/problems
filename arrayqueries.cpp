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
#define pb push_back

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAX = 10e5+10;

int seg[4*MAX];
int a[MAX];
int n, q;

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

void build(int i, int l, int r) {
    // debug(i, l, r);
    if (l == r) {
        seg[i] = a[l];
        return;
    }
    int mid = (l+r)/2;

    build(left(i), l, mid);
    build(right(i), mid + 1, r);

    int segLeft = seg[left(i)];
    int segRight = seg[right(i)];

    seg[i] = (segLeft <= segRight) ? segLeft : segRight;
}

int query(int v, int l, int r, int i, int j) {
    // debug(v, l, r, i, j);
    if (i > r || j < l) return -1;
    if (i <= l && r <= j) return seg[v];

    int segLeft = query(left(v),             l, (l+r)/2, i, j);
    int segRight = query(right(v), (l+r)/2 + 1, r,       i, j);

    if (segLeft == -1) return segRight;
    if (segRight == -1) return segLeft;

    return (segLeft <= segRight) ? segLeft : segRight;
}

int query(int i, int j) {
    return query(1, 1, n, i, j);
}

int main() {

    int t;
    scanf("%i", &t);

    int cnt = 1;
    while (t--) {
        scanf("%i %i", &n, &q);

        for (int i = 1; i <= n; i++)
            scanf("%i", &a[i]);

        build(1, 1, n);

        printf("Case %i:\n", cnt);
    
        for (int j = 0; j < q; j++) {
            int l, r;
            scanf("%i %i", &l, &r);

            int result = query(l, r);
            printf("%i\n", result);
        }
            
        cnt++;
    }
}
