#include <bits/stdc++.h>

using namespace std;

int main() {
    int f; cin >> f;
    
    if (f == 0) {
        printf("0 0 0");
        return 0;
    }

    int b0 = 0; int b1 = 1; int tmp = b1;
    while (b0 + b1 != f) {
        b1 = b0 + b1;
        b0 = tmp;
        tmp = b1;
    }

    printf("0 %d %d\n", b0, b1);
}