#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();

    int count = 0;
    string not_as;
    for (size_t i = 0; i < n; i++) {
        if (s[i] != 'a') {
            not_as += s[i];
            count++;
        }
    }    

    if (count == 0 || count == s.length()) {
        cout << s;
        return 0;
    }
    
    int split = count / 2;
    int rightSide = n - split;

    if (count % 2 != 0) {
        cout << ":(";
        return 0;        
    }

    string s_line = s.substr(rightSide, split);
    
    if (s_line.find("a") != string::npos) {
        cout << ":(";
        return 0;
    }

    string k = not_as.substr(0, split);
    string l = not_as.substr(split, split);
    if (k == l) {
        cout << s.substr(0, rightSide);
    } else {
        cout << ":(";
    }
}