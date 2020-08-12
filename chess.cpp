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

const int sz = 8;
int board[sz][sz];
int remainingCels = 49;

vector<pii> possiblePos(int c, int l){
    vector<pii> pos = {
        {c-1, l+2}, {c-1, l-2},
        {c+1, l+2}, {c+1, l-2},
        {c+2, l+1}, {c+2, l-1},
        {c-2, l+1}, {c-2, l-1}
    };

    return pos;
}

void removeUnableCels(set<pii> v, int rc, int rr){
    for (auto i:v){
        int c=i.first; int r=i.second;
        if ((c>=0 && c<8) && (r>=0 && r<8))
            if (c != rc && r != rr){
                remainingCels--;
                debug(r, c);
            } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string r, k;
    cin>>r>>k;
    debug(r, k);
    int rc=r[0]-'a'; int rr=r[1]-'1';
    int kc=k[0]-'a'; int kr=k[1]-'1';

    debug(rc, rr, kc, kr);
    // for (int i=0; i<sz; i++) board[r[0]-'a'][i] = board[r[1]-1] = 1;
    
    vector<pii> rpos = possiblePos(rc, rr);
    vector<pii> kpos = possiblePos(kc, kr);

    set<pii> pos;
    for (auto p:rpos){
        pos.insert(p);
    }
    for (auto p:kpos){
        pos.insert(p);
    }

    debug(rpos);
    debug(kpos);

    removeUnableCels(pos, rc, rr);

    cout << remainingCels-1 << endl;
}
