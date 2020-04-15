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


	for (int i = 0; i < t; ++i)
	{
		int n;
        scanf("%i\n", &n);

        int count = 2;
        int l = 1;
        int k = 0;
        vi lineb = {1, 1};
        while (count != n) {
            vi line(count+1); line[0] = 1; line[l] = 1;
            for (int j = 1; j < l; j++) {
                if (line[j] == 0) {
                    line[j] = lineb[k] + line[l];
                    k++;
                    l++;
                }
            }

            int p;
            for (p = 0; p < int(lineb.size()); p++)
            {
                lineb[p] = line[p];
            }

            for (int r = p; r < int(line.size()); r++)
            {
                /* code */
                lineb.push_back(line[r]);
            }
            
            
            // lineb.erase(lineb.begin(), lineb.begin()+int(lineb.size()));
            for (int m = 0; m < int(lineb.size()); m++)
            {
                printf("%i ", lineb[m]);
            }
            
            // copy(line.begin(), line.end(), lineb.begin());
            k = 0;
            l = 1;
            // for (int m = 0; m < int(lineb.size()); m++)
            // {
            //     printf("%i ", lineb[m]);
            // }
            printf("\n");
            count++;
            
        }
		printf("Case #%i: ", i+1);
	}
}