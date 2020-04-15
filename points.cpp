#include <bits/stdc++.h>

using namespace std;

#define bs(x, y, z) (binary_search(x, y, z))

int main() {
    int n; cin >> n;

    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }
    
    sort(xs.begin(), xs.end());
    int maxValue = xs[n-1];
    
    vector<int> s; // max possible size is 3
    int powerMax = 30; // approximately 10^9
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= powerMax; j++) {
            int find1 = xs[i] - int(pow(2, j));
            int find2 = xs[i] + int(pow(2, j));
            if (find2 > maxValue) break;
            if (bs(xs.begin(), xs.end(), find1) && bs(xs.begin(), xs.end(), find2)) {
                s = {xs[i] , find1, find2};
                break;
            } else if (bs(xs.begin(), xs.end(), find1)) {
                if (int(s.size()) < 2) s = {xs[i] , find1};
            } else if (bs(xs.begin(), xs.end(), find2)) {
                if (int(s.size()) < 2) s = {xs[i] , find2};
            }
        }
    }

    if (int(s.size()) < 2) {
        for (int i = 0; i < n; i++) {
            if ((xs[i] & (xs[i] - 1)) == 0) {
                printf("1\n");
                printf("%d", xs[i]);
                return 0;
            }
        }

        printf("1\n");
        printf("%d", xs[0]);
        return 0;
    }

    printf("%d\n", int(s.size()));
    for (int i = 0; i < int(s.size()); i++) {
        printf("%d ", s[i]);
    }
    
    printf("\n");
}