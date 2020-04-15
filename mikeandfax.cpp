#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int numPalindromes;
    
    cin >> s;
    cin >> numPalindromes;
    
    int i = 0;
    int size = s.size();
    int len = size/numPalindromes;
    
    if (size % numPalindromes != 0) {
        cout << "NO" << endl;
        return 0;
    }

    while (i < size) {
        int half = (len / 2)+i;
        for (int k = i, j = i+len-1; k < half, j > half-1; k++, j--) {
            if (s[k] != s[j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        i += len;
    }

    cout << "YES" << endl;
}