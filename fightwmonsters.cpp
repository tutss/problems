#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, a, b, k;
    scanf("%i %i %i %i", &n, &a, &b, &k);

    vector<int> monsters(n);
    vector<int> skipsNeeded(n);
    for (int i = 0; i < n; i++) {
        scanf("%i", &monsters[i]);
    }

    int maxPoints = 0;
    for (int i = 0; i < n; i++)
    {
        int remainingHp = monsters[i];
        int bLastAttack = remainingHp % (a+b);
        if (bLastAttack == 0) {
            int stepExtra = a + b;
            int hitExtra = int(ceil(float(stepExtra) / float(a)));
            remainingHp = hitExtra;
        } else {
            int hitExtra = int(ceil(float(bLastAttack) / float(a)));
            remainingHp = hitExtra;
        }
        skipsNeeded[i] = remainingHp - 1;
    }

    sort(skipsNeeded.begin(), skipsNeeded.end());

    for (int i = 0; i < n; i++)
    {
        if (k - skipsNeeded[i] >= 0) {
            maxPoints++;
            k -= skipsNeeded[i];
        } else {
            break;
        }
    }
    
    
    printf("%i\n",maxPoints);
}