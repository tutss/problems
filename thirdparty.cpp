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

    ll libs, vs; cin >> libs >> vs;

    ll ones = 0;
    vector<pair<ll,ll>> vpii(libs);
    for (int i = 0; i < libs; i++) {
        pii tmp; cin >> tmp.first >> tmp.second;
        if (tmp.first == 1) ones++;
        vpii[i] = tmp;
    }

    sort(vpii.begin(), vpii.end());

    vector<vector<ll>> choices;
    for (int j = 0; j < ones; j++) {
        vll selected;
        ll lastEnd = vpii[j].second;
        selected.push_back(j);
        for (int i = j+1; i < libs; i++) {
            pair<ll,ll> f = vpii[i];
            if (f.first - lastEnd == 1 || f.first > lastEnd) {
                lastEnd = f.second;
                selected.push_back(i);
            } 
        }
        
        if (ll(selected.size()) > 0)
            if (vpii[selected[0]].first == 1 && vpii[selected[selected.size()-1]].second == vs) 
                choices.push_back(selected);
    }

    if (ll(choices.size())==0 || ones == 0) {
        cout << "NO" << endl;
        return 0;
    }

    sort(choices.begin(), choices.end(), [](vll a, vll b){
        return ll(a.size()) < ll(b.size());
    });

    cout << "YES" << endl;
    cout << ll(choices[0].size()) << endl;
    for (auto i : choices[0]) {
        cout << i+1 << " ";
    }
    cout << endl;
    

}
