#include <bits/stdc++.h>

using namespace std;

int main() {
    int lines;
    cin >> lines;

    int x1, x2, v1, v2;
    for (size_t i = 0; i < lines; i++)
    {
        cin >> x1 >> x2 >> v1 >> v2;
        if (x1 == x2) {
            cout << 0 << endl;
            continue;
        }
        
        bool possible = false;
        if ((x2-x1) % (v1+v2) == 0) {
            possible = true;
        }

        if (possible) {
            cout << ((x2-x1) / (v1+v2)) << endl;
        } else {
            cout << -1 << endl;
        }
    }
}