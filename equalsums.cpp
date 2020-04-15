#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; cin >> k;

    vector<pair<int, pair<int, int>>> checkSum;

    int n;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> seq(n);
        int sum;
        int ai;
        
        for (int j = 0; j < n; j++) {
            cin >> ai;
            seq[j] = ai;
        }
        sum = accumulate(seq.begin(), seq.end(), 0);
        for (int l = 0; l < n; l++) {
            int sumRemovingElement = sum - seq[l];
            pair<int, int> elemSeq = make_pair(l, i);
            checkSum.push_back(make_pair(sumRemovingElement, elemSeq));
        }
    }

    sort(checkSum.begin(), checkSum.end());
    for (int i = 0; i < checkSum.size() - 1; i++)
    {
        int firstSum = checkSum[i].first;
        int firstElem = checkSum[i].second.first;
        int firstSeq = checkSum[i].second.second;
        int nextSum = checkSum[i+1].first;
        int nextElem = checkSum[i+1].second.first;
        int nextSeq = checkSum[i+1].second.second;
        if (firstSeq != nextSeq) {
            if (firstSum == nextSum) {
                printf("YES\n%d %d\n%d %d", firstSeq+1, firstElem+1, nextSeq+1, nextElem+1);
                return 0;
            }
        }
    }
    
    printf("NO\n");
        
}