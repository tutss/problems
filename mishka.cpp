#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> prblms(n);
    for (int i = 0; i < n; i++) {
        cin >> prblms[i];
    }

    int begin = 0;
    int end = n-1;

    int count = 0;
    while (begin <= end) {
        if (prblms[begin] <= k) {
            count++;
            begin++;    
        } else if (prblms[end] <= k) {
            count++;
            end--;
        } else {
            break;
        }
    }

    printf("%d", count);
}