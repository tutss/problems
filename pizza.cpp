#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    long n_friends;
    cin >> n_friends;

    if (n_friends == 0) {
        cout << 0;
    } else {
        if (n_friends % 2 == 0) {
            cout << n_friends+1;
        } else {
            cout << (ll) (n_friends+1)/2;
        }
    }
}