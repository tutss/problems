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

    const int m = n*2+1;
    int dime[m][m] = {};
    fill(*dime, *dime + m*m, n+1);
    
    dime[n][n]=n;
    for (int i = 0; i < n; i++) {
        dime[n][i] = i;
        dime[i][n] = i;
        if (i > 0) {
            int k = 0;
            for (int j = n-i; j < n; j++) {
                dime[i][j] = k;
                k++;
            }

            int p = 0;
            for (int j = m-n+i-1; j > n; j--) {
                dime[i][j] = p;
                p++;
            }
        }
    }

    for (int i = n+1; i < m; i++) {
        int k = 0;
        for (int j = i-n; j < n; j++) {
            dime[i][j] = k;
            k++;
        }

        int p = 0;
        for (int j = m-i+n-1; j > n; j--) {
            dime[i][j] = p;
            p++;
        }
    }    

    int j = n-1;
    for (int i = n+1; i < m; i++) {
        dime[n][i] = j;
        dime[i][n] = j;
        j--;
    }

    for (int i=0; i < m; i++) {
        for (int j=0; j < m; j++) {
            if (dime[i][j] == n+1 && j < n) cout << "  ";
            else if (dime[i][j] == n+1 && j > n) break;
            else if (dime[i][j] == 0 && j >= n) cout << dime[i][j]; 
            else cout << dime[i][j] << " ";
            if (i ==  m-1 && j == n) break;
        }
        cout << endl;
    }
}
