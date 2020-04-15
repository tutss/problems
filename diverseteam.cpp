#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;


    vector<int> inp;
    vector<int> indexes;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j > k) break;
        int tmp; cin >> tmp;
        if (find(inp.begin(), inp.end(), tmp) == inp.end()) {
            inp.push_back(tmp);
            indexes.push_back(i);
            j++;
        }
    }

    sort(indexes.begin(), indexes.end());
    if (indexes.size() >= k) {
        printf("YES\n");    
        for (int i = 0; i < k; i++) {
            printf("%d ", indexes[i]+1);
        }
        return 0;
    }


    printf("NO\n");
}