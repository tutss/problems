#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

// vi _lisN2Elems(vi v) {
//     int n = int(v.size());

//     vi dp(n);
//     dp[0] = 1;

//     int maxx = 1;
//     vi l;
//     for (int i = 1; i < n; i++) {
//         int maxv = 0;
//         int cnt = 0;
//         for (int j = 0; j < i; j++) {
//             if (v[i] > v[j]) {
//                 maxv = max(dp[j], maxv);
//                 l.push_back(v[j]);       
//             }
//         }

//         for (int k : l) cout << k << " ";
//         cout << endl;
        
//         // if (int(l.size()) > cnt) {
//         //     cnt = int(l.size());
//         //     l.clear();
//         // }

//         dp[i] = maxv + 1;
//         maxx = max(maxx, dp[i]);
//     }

//     for (int i : l) cout << i << " ";
//     cout << endl;

//     return l;
// }

int _lisN2(vi v) {
    int n = int(v.size());

    vi dp(n);
    dp[0] = 1;

    int maxx = 1;
    for (int i = 1; i < n; i++) {
        int maxv = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) maxv = max(dp[j], maxv);
        }
        dp[i] = maxv + 1;
        maxx = max(maxx, dp[i]);
    }

    return maxx;
}

int _lisBinarySearch(vi v) {
    int n = int(v.size());
    vi dp(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.begin()+len, v[i]) - dp.begin();
        dp[j] = v[i];
        if (j == len) len++; 
    }

    return len;
}


int main() {
    // vi v = {1, 2, 3, 4};
    // vi v2 = {10, 2, 7, 15, 21};
    
    // vi r1 = _lisN2Elems(v2);
    // vi r2 = _lisN2Elems(v2);
    int n = 20;
    int t = 10000;

    vi v(n);
    map<int, int> freqs;

    while (t >= 0) {
        srand (time(NULL)+t);
        for (int i = 0; i < n; i++) v[i] = i + (rand() % 100);

        int lis = _lisBinarySearch(v);
        freqs[lis]++;

        t--;
    }

    for (auto it = freqs.begin(); it != freqs.end(); ++it) {
        printf("key=%i -> %i\n", it->first, it->second);
    }
}
