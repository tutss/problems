#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args...)

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n;
    cin >> n;

    string s; string t;
    cin >> s; cin >> t;

    vi pos1; vi pos2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' && t[i] == 'b') {
            pos1.push_back(i);
        } else if (s[i] == 'b' && t[i] == 'a') {
            pos2.push_back(i);
        }
    }

    if (int(pos1.size()) % 2 != int(pos2.size()) % 2) {
        printf("-1\n");
        return 0;
    }

    vector<tupl> ps;
    for (int i = 0; i+1 < int(pos1.size()); i+=2) {
        ps.push_back({pos1[i], pos1[i+1]});
    }
    
    for (int i = 0; i+1 < int(pos2.size()); i+=2) {
        ps.push_back({pos2[i], pos2[i+1]});
    }

    if (int(pos1.size()) % 2 && int(pos2.size()) % 2) {
        ps.push_back({pos1.back(), pos1.back()});
        ps.push_back({pos1.back(), pos2.back()});
    }

    printf("%i\n", int(ps.size()));
    for (tupl p : ps) {
        printf("%i %i\n", p.first+1, p.second+1);
    }
}
