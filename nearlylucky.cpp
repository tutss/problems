#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    string n;
    cin >> n;

    ll count = 0;
    for (int i = 0; i < int(n.size()); i++) {
        if (n[i] == '4' || n[i] == '7') count++;
    }
    
    string c = to_string(count);
    for (int i = 0; i < int(c.size()); i++) {
        if (c[i] != '4' && c[i] != '7') {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
