#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        v[i] = make_pair(tmp-1, i);
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (v[i].first > v[i].second) {
            
        }
    }
    
}