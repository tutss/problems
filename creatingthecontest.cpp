#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    int n;
    cin >> n;
    vll diff(n);
    for (int i = 0; i < n; i++) {
        cin >> diff[i];
    }
    int maxx = 0;
    int last = 0;
    int selected = 1;
    for (int j = 0; j < n; j++) {
        if (diff[j] <= 2*last) {
            selected++;
        } else {
            selected = 1;
        } 
        last = diff[j];
        maxx = max(selected, maxx);
    }

    cout << maxx << endl;
}