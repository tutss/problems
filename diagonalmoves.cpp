#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    int q; 
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        if (k < max(x, y)) {
            cout << -1 << endl;
        } else if (k == max(x, y)) {
            if (max(x, y) % 2 == 0) {
                if (min(x, y) != k) {
                    cout << k-1 << endl;
                } else {
                    cout << k << endl;
                }
            } else {
                cout << k << endl;
            }
        } else {
            if (x == y) {
                if (x==1 && y==1) {
                    if (k%2==0) {
                        cout << k - 2 << endl;
                    } else {
                        cout << k << endl;
                    }
                } else {
                    if (k % 2 == 0) {
                        cout << k << endl;
                    } else {
                        cout << k - x << endl;
                    }
                }
            } else {
                cout << k-1 << endl;
            }
        }
    }
    
}