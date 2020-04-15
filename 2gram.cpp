#include <bits/stdc++.h>

using namespace std;

int main() {
    int len;
    string s;

    cin >> len;
    cin >> s;

    map<string, int> dict;

    for (int i = 0; i < len-1; i++)
    {
        string tmp;
        tmp += s[i];
        tmp += s[i+1];
        dict[tmp] += 1;
    }

    int currentMax = 0;
    string max = "";
    for (auto it = dict.cbegin(); it != dict.cend(); ++it) {
        if (it->second > currentMax) {
            max = it->first;
            currentMax = it->second;
        }
    }
    
    cout << max << endl;
    
}