#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        string n; cin >> n;

        string one = "";
        int index = int(n.size());
        for (int k = 0; k < int(n.size()); k++) {
            char now = n[k];
            if (now == '4') {
                if (k < index) index = k;
                now = '3';
            }
            one.push_back(now);
        }

        string two = "";
        for (int j = index; j < int(n.size()); j++) {
            if (n[j] == '4') two.push_back('1');
            else two.push_back('0');
        }
        
        printf("Case #%d: %s %s\n", i+1, one.c_str(), two.c_str());
    }
    
}