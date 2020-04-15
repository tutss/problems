#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0;
    for (size_t i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        total += p;
    }
    
    cout << n - ((n*5) - total) / 5 << endl;
    return 0;
}