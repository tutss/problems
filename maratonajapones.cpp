#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, pair<int, int>> tripl;

const int width = 1000;
const int height = 1000;

bool insideTable(int x, int y, int r) {
    if (((x >= 0) && (y >= 0)) && ((x <= width) && (y <= height))) return true;
    else return false;
}

int main() {
    int q;
    scanf("%i\n", &q);

    set<tripl> queries; // (x, y, r)
    int i = q;
    while (i > 0) {
        char op; scanf("%c ", &op);
        int x, y, r; scanf("%i %i %i\n", &x, &y, &r);

        tripl qi = make_pair(x, make_pair(y, r));

        // printf("\tOP %c\n", op);
        // printf("\tx -> %i | y -> %i | r -> %i\n", x, y, r);
        if (op == 'A') {
            if (insideTable(x, y, r)) {
                bool in = true;
                for (auto it : queries) {
                    int x1 = it.first; int y1 = it.second.first;
                    int r1 = it.second.second;
                    int d2 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
                    int rd = (r + r1) * (r + r1);
                    // printf("\tx1 -> %i | y1 -> %i | r1 -> %i\n", x1, y1, r1);
                    // printf("\td -> %lf\n", d2);
                    if (d2 < rd) {
                        printf("No\n");
                        in = false;
                        break;
                    }
                }
                if (in) {
                    printf("Ok\n");
                    queries.insert(qi);
                }
            }
        } else {
            if (queries.count(qi)) {
                queries.erase(qi);
                printf("Ok\n");
            } else {
                printf("No\n");
            }
        }
        
        i--;
    }
}
