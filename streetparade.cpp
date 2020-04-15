#include <bits/stdc++.h>

using namespace std;

int main() {

    while (true) {
        int n; scanf("%i", &n);
        if (n == 0) break;
        deque<int> q;

        int i = 0;
        bool printno = false;
        while (n != 0)
        {
            int car; scanf("%i", &car);
            car--;
            
            int min = 1001, max = 0;
            for (auto it = q.begin(); it != q.end(); ++it) {
                if (*it < min) min = *it;
                if (*it > max) max = *it;
            }


            if (i != car) {
                if (car > min && !q.empty()) printno = true;
                min = car;
                q.push_back(car);
            } else {
                i++;
                int step=1;
                while (!q.empty() && q.back() == car+step) {
                    q.pop_back();
                    step++;
                    i++;
                }
            }

            --n;
        }

        printno ? printf("no\n") : printf("yes\n");
    }
    
}