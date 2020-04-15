#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int coin; scanf("%i", &coin);
    int happiness = 0;
    map<int,int> coinsValues = {{500,1000}, {5,5}};
    while (coin >= 0) {
        if (coin - 500 >= 0) {
            coin -= 500;
            happiness += 1000;
        } else if (coin - 5 >= 0) {
            coin -= 5;
            happiness += 5;
        } else {
            break;
        }
    }

    printf("%i", happiness);
}
