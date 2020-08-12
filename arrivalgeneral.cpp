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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    vi v(n); 
    for (int i =0; i < n; i++) {
        cin >> v[i];
    }

    vi c;
    for (int i : v) {
        c.push_back(i);
    }
    sort(c.begin(), c.end());

    int maxx = c[n-1];
    int minx = c[0];

    int maxindex; 
    int minindex;
    bool check = true;
    for (int i = 0; i <n; i++) {
        if (v[i] == maxx && check) {
            maxindex = i;
            check = false;
        }
        else if (v[i] == minx) minindex = i;
    }

    debug(maxindex, minindex);

    if (maxindex > minindex) {
        cout << (maxindex)+abs(minindex-(n-1))-1;
    } else {
        cout << (maxindex)+((n-1)-minindex);
    }
}
