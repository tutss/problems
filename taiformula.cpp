#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    double area = 0.0;

    long time; float c;
    scanf("%ld %f", &time, &c);
    for (int i = 0; i < n-1; i++) {
        long ti; float ci;
        scanf("%ld %f", &ti, &ci);
        area += (ci + c)*(ti-time)/2;
        time = ti; c = ci;
    }

    printf("%f", area/1000);   
}