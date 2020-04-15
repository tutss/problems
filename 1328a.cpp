#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int a, b; 
        scanf("%i %i", &a, &b);

        if (a % b == 0) printf("0\n");
        else printf("%i\n", b - a%b);        
    }
}
