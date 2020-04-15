#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    int n; cin >> n;
    vll seq;
    
    set<ll> numbs;
    vll ordered(n);

    ll mainNumber;
    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        seq.push_back(tmp);
        numbs.insert(seq[i]);
    }

    for (int i = 0; i < n; i++) {
        ll doub = seq[i]*2; ll triple = seq[i]/3;
        if (numbs.find(doub) != numbs.end()) continue;
        if (numbs.find(triple) != numbs.end() && seq[i] % 3 == 0) continue;
        mainNumber = seq[i];
        break;
        
    }

    ordered[n-1] = mainNumber;

    for (int i = n-1; i > 0; i--) {
        if (numbs.find(ordered[i] * 3) != numbs.end()) 
            ordered[i-1] = ordered[i] * 3;
        else if (numbs.find(ordered[i] / 2) != numbs.end()) 
            ordered[i-1] = ordered[i] / 2;
    }
    
    for (auto it = ordered.begin(); it != ordered.end(); ++it) 
        cout << *it << " "; 
    cout << endl;
    
}