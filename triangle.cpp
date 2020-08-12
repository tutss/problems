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

vector<vector<int>> comb(vi lens) {
    string mask(3, 1);
    mask.resize(4, 0);

    vector<vector<int>> permutations;
    do {
        vi perm;
        for (int i = 0; i < 4; i++) {
            if (mask[i]) perm.pb(lens[i]);
        }
        permutations.pb(perm);
    } while (prev_permutation(all(mask)));

    return permutations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vi lens = {a, b, c, d};
    vector<vector<int>> perms = comb(lens);

    bool triangle = false;
    bool segment = false;
    for (vector<int> v : perms) {
        sort(all(v));
        int x = v[0]; int y = v[1];
        if (x + y > v[2]) {
            triangle = true;
        } else if (x + y == v[2]) {
            segment = true;
        }
    }

    if (triangle) {
        cout << "TRIANGLE" << endl;
    } else if (segment) {
        cout << "SEGMENT" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
