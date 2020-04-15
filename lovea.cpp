#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int len = s.size();

    float numAs = 0.0;
    for (size_t i = 0; i < len; i++) {
        if (s[i] == 'a') {
            numAs++;
        }
    }

    float prop = numAs/len;
    if (prop > 0.5) {
        cout << len;
    } else {
        int count = 0;
        for (size_t i = 0; i < len; i++) {
            if (s[i] != 'a') {
                count++;
                prop = numAs / (len - count);
                if (prop > 0.5) {
                    cout << len - count;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}