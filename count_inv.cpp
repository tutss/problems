#include <bits/stdc++.h>

using namespace std;

long long merge(int v[], int tmp[], int l, int m, int r) {
    int i = l, j = m, p = l;
    long long inversions = 0;

    while (i < m  && j <= r) {
        if (v[i] <= v[j]) { 
            tmp[p++] = v[i++];
        } else {
            tmp[p++] = v[j++];
            inversions += m - i; 
        }
    }

    while (i < m) tmp[p++] = v[i++];
    while (j <= r) tmp[p++] = v[j++];

    i = l;
    while (i <= r) {
        v[i] = tmp[i];
        i++;
    }
    
    return inversions;
}

long long mergesort(int v[], int tmp[], int l, int r) {
     int m = 0; 
     long long inversions = 0;
     
    if (r > l) {
        m = (r+l) / 2;
        inversions = mergesort(v, tmp, l, m);
        inversions += mergesort(v, tmp, m+1, r);
        inversions += merge(v, tmp, l, m+1, r);
    }
    
    return inversions;
}

int main() {
    int t; cin >> t;

    while (t > 0) {
        int n; cin >> n;
        int v[n]; int v_[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        cout << mergesort(v, v_, 0, n-1) << endl;
        t--;
    }
}