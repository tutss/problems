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

int n, k;
string s;

int solve(char x){
    int cnt=0, mx=0;
    int r=0;
    for (int l = 0; l<n; l++){
        while (r<n && (cnt<k || s[r]!=x)) {
            if (s[r]==x) cnt++;
            r++;
        }
        if (s[l]==x) cnt--;
        if (mx < r-l) mx = r-l;
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    
    int a = solve('a');
    int b = solve('b');

    cout << max(a, b) << endl;

    // n2
    // for (int i=0; i<n; i++){
    //     char at = s[i];
    //     if (i>0 && s[i-1]==at) continue;
    //     int j = i+1;
    //     int subs = k;
    //     while (j < n){
    //         if (s[j]!=at && subs>0){
    //             subs--;
    //         } else if (s[j]!=at && subs<=0){
    //             break;
    //         }
    //         j++;
    //     }
    //     ans = max(ans, j-i);
    // }

}
