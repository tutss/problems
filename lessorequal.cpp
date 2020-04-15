#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    map<int, int> frequency;

    cin >> n >> k;

    int ai;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        frequency[ai]++;
    }

    int cumulativeSum = 0;
    for (auto it = frequency.cbegin(); it != frequency.cend(); ++it) {
        if (it == frequency.cbegin()) {
            if (k == 0) {
                int min = it->first-1;
                if (min > 0) {
                    cout << min << endl;
                } else {
                    break;
                }
                return 0;
            }
            if (it->second == k) {
                cout << it->first << endl;
                return 0;
            } else if (it->second > k) {
                break;
            }
            cumulativeSum += (int) it->second;
        } else {
            cumulativeSum += (int) it->second;
            if (cumulativeSum == k) {
                cout << it->first << endl;
                return 0;
            } else if (cumulativeSum > k) {
                break;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}