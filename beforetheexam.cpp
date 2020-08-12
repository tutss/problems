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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d, sumTime;
    cin >> d >> sumTime;
    vi mins(d); vi maxs(d);
    for (int i=0; i<d; i++) {
        cin >> mins[i] >> maxs[i];
    }

    int minSum = accumulate(all(mins), 0);
    int maxSum = accumulate(all(maxs), 0);

    if (minSum > sumTime || maxSum < sumTime) {
        cout << "NO" << endl;
        return 0;
    }

    int r = sumTime;
    vi times;
    for (int i=0; i<d-1; i++) {
        int mnD = mins[i]; 
        int mnDnext = accumulate(mins.begin()+(i+1), mins.end(), 0);
        int mxD = maxs[i];
        int j;
        for (j=mxD; j>=mnD; j--) {
            if (r-j >= mnDnext) break;
        }
        r -= j;
        if (r<0) break;
        times.pb(j);
    }
    times.pb(r);

    cout << "YES" << endl;

    for (int i : times) {
        cout << i << " ";
    }
}
