#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n;
    scanf("%i", &n);

    vi v(n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%i", &tmp);
        v[i] = tmp;
    }
    

    int sereja = 0;
    int dima = 0;

    int round = 1;
    int i = 0;
    int j = n-1;
    while (i <= j) {
        int s;
        if (round % 2 == 0) {
            if (v[i] > v[j]) {
                s = v[i];
                i++;
            } else {
                s = v[j];
                j--;
            }
            dima += s;
        } else {
            if (v[i] > v[j]) {
                s = v[i];
                i++;
            } else {
                s = v[j];
                j--;
            }
            sereja += s;
        }
        round++;
    }
    
    printf("%i %i\n", sereja, dima);
}
