#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    string t;

    cin >> n >> k;
    cin >> t;

    int i;
    for (i = 1; i < n; i++) {
        string first; string second;
        first = t.substr(0, n-i); second = t.substr(i, n);

        if (first == second) break;
    }
    
    printf("%s", t.c_str());
    for (int j = 1; j < k; j++) {
        printf("%s", t.substr(n-i).c_str());
    }

}