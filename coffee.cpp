#include<bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    if (int(s.size()) == 6) {
        if (s[2] == s[3] && s[4] == s[5]) {
            printf("Yes");
        } else {
            printf("No");
        }
    } else {
        printf("No");
    }
}