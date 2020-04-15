#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,z,w;
    cin >> x >> y >> z >> w;

    vector<int> values = {x, y, z, w};
    sort(values.begin(), values.end());

    int max = values.back();
    int a = max - values[0];
    int b = values[2] - a;
    int c = values[1] - a; 

    printf("%d %d %d\n", a, b, c);
}