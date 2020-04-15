#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string t; cin >> t;


    vector<int> divs;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            divs.push_back(i);
    }
    divs.push_back(n);

    int i, j, z;
    i = 0, j = 0, z = 0;
    while (j != n-1) {
        j = divs[z]-1;
        while (i <= j && i < n && j > 0) {
            char tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
            i++;
            j--;
        }
        i = 0; 
        j = divs[z]-1;
        z++;
    }
    
    cout << t << endl;
    
}