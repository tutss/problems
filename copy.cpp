#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t > 0) {
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            s.insert(tmp);
        }

        printf("%d\n", int(s.size()));
        t--;
    }
}