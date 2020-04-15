#include <bits/stdc++.h>

using namespace std;

int countSwaps(string s) {
    int swaps = 0;

    int n = s.size();

    int first = -1;
    int last = -1;

    for (int i = 0; i < n; i++) 
        if (s[i] == '1') {
            first = i;
            break;
        }
    
    if (first == -1) return 0;

    for (int i = n-1; i > 0; i--)
        if (s[i] == '1') {
            last = i;
            break;
        }
    
    for (int i = first; i <= last; i++)
        if (s[i] == '0') swaps++;

    return swaps;
}

int main() {
    int numStrings;
    cin >> numStrings;
    for (size_t i = 0; i < numStrings; i++) {
        string s;
        cin >> s;
        int swaps = countSwaps(s);
        cout << swaps << endl;
    }
    
}