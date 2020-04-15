#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n; scanf("%i", &n);
    
    long sumA=0; 
    long sumB=0; 
    long sumC=0; 
    long sumD=0;
    
    int team = 1;
    for (int i = 0; i < n; i++) {
        int point; scanf("%i", &point);
        if (team == 1) {
            sumA += point;
        } else if (team == 2) {
            sumB += point;
        } else if (team == 3) {
            sumC += point;
        } else {
            sumD += point;
        }
        team++;
        team = team % 4;
    }

    map<long, char> sums = {
        {sumA, 'A'}, 
        {sumB, 'B'}, 
        {sumC, 'C'}, 
        {sumD, 'D'}
    };
    
    long max = 0;
    char maxx = 'A';
    for (auto it = sums.begin(); it != sums.end(); ++it) {
        if (it->first > max) {
            max = it->first;
            maxx = it->second;
        }
    }

    printf("%c\n", maxx);
    
}
