#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

vi horses;

int main() {
    int k, n; scanf("%i %i", &k, &n);
    for (int i = 0; i < n; i++)
    {
        int t; scanf("%i", &t);
        horses.push_back(t);
    }

    vi dists;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) continue;
        dists.push_back(horses[i]- horses[i-1]);
    }
    dists.push_back(k-horses[n-1]+horses[0]);

    sort(dists.begin(), dists.end());
    reverse(dists.begin(), dists.end());
    printf("%i", k - dists[0]);
    
}
