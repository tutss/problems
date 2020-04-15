#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n; cin >> k;
    string s; cin >> s;

    map<char, vector<int>> m;
    for (int i = 0; i < n; i++) {
        m[s[i]].push_back(i);
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (k <= 0) break;
        int vsize = int(it->second.size());
        if (vsize > 0) {
            for (int i = 0; i < vsize; i++) {
                if (k > 0) {
                    s[it->second[i]] = 'X';
                    k--;
                } else {
                    break;
                }
            }
        }   
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'X') {
            cout << s[i];
        }
    }       

}