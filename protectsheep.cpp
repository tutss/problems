#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

const int MAX = 500*500;

int main() {
    int r, c; scanf("%i %i", &r, &c);
    int n = r*c;

    vector<char> field;
    while (int(field.size()) != n) {
        char inp; 
        scanf("%c", &inp);
        if (!isspace(inp)) field.push_back(inp);
        
    }

    vi adj[MAX];
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (i + c < n) {
            adj[i].push_back(i+c);
            // printf("fi: %c, fi+c: %c\n", field[i], field[i+c]);
            if ((field[i] == 'S' && field[i+c] == 'W') || (field[i] == 'W' && field[i+c] == 'S')) possible = false;
        }
        if (i - c >= 0) {
            adj[i].push_back(i-c);
            // printf("fi: %c, fi-c: %c\n", field[i], field[i-r]);
            if ((field[i] == 'S' && field[i-c] == 'W') || (field[i] == 'W' && field[i-c] == 'S')) possible = false;
        }
        if ((i%c)+1 < c) {
            adj[i].push_back(i+1);
            // printf("fi: %c, fi+1: %c\n", field[i], field[i+1]);
            if ((field[i] == 'S' && field[i+1] == 'W') || (field[i] == 'W' && field[i+1] == 'S')) possible = false;
        }
        if (i%c != 0) {
            adj[i].push_back(i-1);
            // printf("fi: %c, fi-1: %c\n", field[i], field[i-1]);
            if ((field[i] == 'S' && field[i-1] == 'W') || (field[i] == 'W' && field[i-1] == 'S')) possible = false;
        }

        if (!possible) break;
    }

    // for (int i = 0; i < n; i++) {
    //     printf("i: %i || ", i);
    //     for (int j = 0; j < int(adj[i].size()); j++) {
    //         printf("%i ", adj[i][j]);
    //     }
    //     printf("\n");
    // }
    

    if (possible) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            if (field[i] == '.') cout << 'D';
            else cout << field[i];
            if (i%c == c-1) cout << endl;
        }
    } else {
        printf("No\n");
    }
}
