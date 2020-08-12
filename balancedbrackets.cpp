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

bool match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return true;
    return false;
}

bool closing(char c) {
    if (c == ')' || c == ']' || c == '}') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        bool itsOk = true;
        stack<char> st;
        for (char c : s) {
            if (closing(c)) {
                if (int(st.size()) == 0) {
                    itsOk = false;
                    break;
                }
                if (match(st.top(), c)) {
                    st.pop();
                } else {
                    itsOk = false;
                }
            } else {
                st.push(c);
            }

            if (itsOk) continue;
            else break;
            
        }

        if (itsOk) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
