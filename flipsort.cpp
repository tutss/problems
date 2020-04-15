#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

// same code of count inversions
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
    int n;
    while (scanf("%i", &n) != EOF) {
        int numbers[n]; int _numbs[n];
        for (int i = 0; i < n; ++i) scanf("%i", &numbers[i]);
        
        printf("Minimum exchange operations : %lld\n", mergesort(numbers, _numbs, 0, n-1));
    }
}
