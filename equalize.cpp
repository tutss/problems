#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int frac = n/m;

    map<int, vector<int>> remainderCount;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        int r = tmp%m; 
        remainderCount[r].push_back(tmp);
    }



    for (int i = 0; i < m-1; i++) {
        int j = 0;
        while (int(remainderCount[i].size()) > frac) {
            int nm = remainderCount[i][j];
            int s = nm+1;
            if (int(remainderCount[i+1].size()) < frac) {
                remainderCount[s].push_back(s);
            }
        }
        j++;
    }
    

    // for (auto it = count.begin(); it != count.end(); ++it) {
    //     printf("[%d] = %d\n", it->first, it->second);
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     printf("(remainder: %d, number: %d)\n", remainders[i].first, remainders[i].second);
    // }
    

    // cout << sum << endl;
    
    
}