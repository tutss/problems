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
typedef pair<int, pair<int, pair<queue<int>, queue<int>>>> piv;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k1, k2;
    // p1 card, p2 card, p1 size, p2 size
    map<piv, bool> mapState;
    queue<int> p1; queue<int> p2;

    cin >> n;

    cin >> k1;
    for (int j = 0; j < k1; j++) {
        int c; cin >> c;
        p1.push(c);
    }

    cin >> k2;
    for (int j = 0; j < k2; j++) {
        int c; cin >> c;
        p2.push(c);
    }

    // cout << "p1\n";
    // while (!p1.empty()) {
    //     cout << p1.front() << " ";
    //     p1.pop();
    // }
    // cout << endl;
    
    int cnt = 0;
    while (!p1.empty() && !p2.empty()) {
        piv state = {p1.front(), {p2.front(), {p1, p2}}};
        
        // debug(state, p1.size(), p2.size());
        p1.pop(); p2.pop();

        if (mapState[state] == true) {
            cout << -1 << endl;
            return 0;
        } else {
            mapState[state] = true;
            if (state.first > state.second.first) {
                p1.push(state.second.first);
                p1.push(state.first);
            } else if (state.second.first > state.first) {
                p2.push(state.first);
                p2.push(state.second.first);
            }
        }

        cnt++;
    }

    cout << cnt << " ";
    if (p1.empty()) {
        cout << 2 << endl;
    } else if (p2.empty()) {
        cout << 1 << endl;
    }
}
